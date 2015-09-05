#include "stdafx.h"
#include "ProtocolModule.h"
#include "LogMgr.h"
#include "ModuleMgr.h"

#include "echo_str.pb.h"
#include <iostream>
#include <sstream>

unsigned ProtocolModule::ModuleId = 0;

ProtocolModule::ProtocolModule()
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	m_pNetworkModule = (NetworkModule*)ModuleMgr::getInstance()->getModuleById( NetworkModule::getStaticModuleId() );
	m_pLogModule = (LogModule*)ModuleMgr::getInstance()->getModuleById( LogModule::getStaticModuleId() );
}


ProtocolModule::~ProtocolModule()
{
	m_pNetworkModule = nullptr;
	m_pLogModule = nullptr;

	google::protobuf::ShutdownProtobufLibrary();
}

void ProtocolModule::install()
{
	m_pDelegate = MakeDelegate( this, &ProtocolModule::onRecvPackageHandler );

	m_pNetworkModule->Register( NetworkEvent::RECV_PACKAGE, m_pDelegate );

	printf( "ProtocolModule install succeed!\n" );
}

void ProtocolModule::uninstall()
{
	m_pNetworkModule->UnRegister( NetworkEvent::RECV_PACKAGE, m_pDelegate );

	delete m_pDelegate;
	m_pDelegate = nullptr;

	printf( "ProtocolModule uninstall succeed!\n" );
}

void ProtocolModule::onRecvPackageHandler( const CBaseEvent& evt )
{
	
	IO_COMPLETE_DATA* p_io_complete_data = (IO_COMPLETE_DATA*)evt.m_pArgs;

	TEST::Echo_Str p;
	p.ParseFromString( p_io_complete_data->buffer );
	p.text();

	std::cout << p_io_complete_data->usMsgId << "\t" << p.text() << std::endl;
	std::ostringstream strStream;
	strStream << "(MSG_ID):" << p_io_complete_data->usMsgId << ",(TEXT)" << p.text();

	m_pLogModule->push_log( NetworkModule::getModuleName(), strStream.str() );
}