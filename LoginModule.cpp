#include "stdafx.h"
#include "iostream"
#include "sstream"

#include "LoginModule.h"
#include "ModuleMgr.h"
#include "LoginProtocol.h"
#include "charset.h"
#include "DataBaseModule.h"

#include "chatapp.pb.h"
#include "login.pb.h"
#include "response.pb.h"

unsigned LoginModule::ModuleId = 0;
LoginModule::LoginModule()
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	m_pNetworkModule = (NetworkModule*)ModuleMgr::getInstance()->getModuleById( NetworkModule::getStaticModuleId() );
	m_pLogModule = (LogModule*)ModuleMgr::getInstance()->getModuleById( LogModule::getStaticModuleId() );

	m_pDataBase = ((DataBaseModule*)ModuleMgr::getInstance()->getModuleById( DataBaseModule::getStaticModuleId() ))->getDataBaseProxy();
}


LoginModule::~LoginModule()
{
	m_pNetworkModule = nullptr;
	m_pLogModule = nullptr;
	m_pDataBase = nullptr;

	google::protobuf::ShutdownProtobufLibrary();
}

void LoginModule::install( void )
{
	m_pDelegate = MakeDelegate( this, &LoginModule::onRecvPackageHandler );

	m_pNetworkModule->Register( LoginProtocol::LOGIN, m_pDelegate );

	printf( "LoginModule install succeed!\n" );

}

void LoginModule::uninstall( void )
{
	m_pNetworkModule->UnRegister( LoginProtocol::LOGIN, m_pDelegate );

	delete m_pDelegate;
	m_pDelegate = nullptr;

	printf( "LoginModule uninstall succeed!\n" );
}

void LoginModule::onRecvPackageHandler( const CBaseEvent& evt )
{

	IO_COMPLETE_DATA* p_io_complete_data = (IO_COMPLETE_DATA*)evt.m_pArgs;
	//p_io_complete_data->usClientSocket
	/*TEST::Echo_Str p;
	p.ParseFromString( p_io_complete_data->buffer );
	p.text();*/
	//ChatApp::User p;
	//p.ParseFromString( p_io_complete_data->buffer );

	//std::cout << p_io_complete_data->usMsgId << "\t" << UTF8ToGBK( p.name() ) << "\t" << UTF8ToGBK( p.chat() ) << std::endl;
	/*std::ostringstream strStream;
	strStream << "(MSG_ID):" << p_io_complete_data->usMsgId << ",(TEXT)" << p.name() << "\t" << p.chat();
	m_pLogModule->push_log( NetworkModule::getModuleName(), strStream.str() );*/


	LoginProto::Login p;
	p.ParseFromString( p_io_complete_data->buffer );
	free(p_io_complete_data->buffer);
	//std::cout << p_io_complete_data->usMsgId << "\t" << UTF8ToGBK( p.name() ) << "\t" << UTF8ToGBK( p.pwd() ) << std::endl;

	std::string sql = "select * from user where name = '"+p.name()+"' and pwd ='"+p.pwd()+"'";
	std::string result = m_pDataBase->select_sql( sql );

	printf( result.c_str() );

	std::string resStr;

	CommonProto::Response resps;
	if ( result.size() == 0 )
	{
		//resStr = UTF8ToGBK("查询失败");
		resStr = "select failed";
		resps.set_id( 1 );
	}
	else
	{
		//resStr = UTF8ToGBK("查询成功");
		resStr = "select succeed";
		resps.set_id( 0 );
	}
	resps.set_desc( resStr );
	resps.SerializeToString( &resStr );

	m_pNetworkModule->Send( p_io_complete_data->usClientSocket, resStr, p_io_complete_data->usMsgId );
}