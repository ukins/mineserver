#include "stdafx.h"
#include "NetworkModule.h"
#include "ModuleMgr.h"

unsigned NetworkModule::ModuleId = 0;

NetworkModule::NetworkModule()
{
	m_pNetworkSrv = new CNetworkMgr;

	m_pTimeModule = (TimeModule*)ModuleMgr::getInstance()->getModuleById( TimeModule::getStaticModuleId() );
}


NetworkModule::~NetworkModule()
{
	delete m_pNetworkSrv;
	m_pNetworkSrv = nullptr;
}

void NetworkModule::install()
{
	if ( !m_pNetworkSrv->Init() )
	{
		m_pNetworkSrv->Exit();
		throw "Error: NetworkSrv Init failed";
	}

	if ( !m_pNetworkSrv->Startup() )
	{
		m_pNetworkSrv->Exit();
		throw "Error: NetworkSrv Startup failed";
	}

	printf( "NetworkModule install succeed!\n" );

}

void NetworkModule::uninstall()
{
	m_pNetworkSrv->Stop();

	m_pNetworkSrv->Exit();

	printf( "NetworkModule uninstall succeed!\n" );
}

void NetworkModule::dispatchEvent( const CBaseEvent& evt )
{
	Lock localLock( &m_Lockable );	//同步锁

	BaseModule::dispatchEvent( evt );

	m_pTimeModule->tick();	//将定时器整合到网络模块中
}

void NetworkModule::Send( SOCKET s, std::string buffer, u_short protocolId )
{
	CConnectMgr *pConnectMgr = CConnectMgr::GetInstance();
	CConnect* conn = pConnectMgr->GetConnectBySocket( s );
	//conn->m_oIO.buffer = buffer;
	//ZeroMemory( &conn->m_oIO, sizeof( conn->m_oIO ) );

	conn->m_oIO.hdr.usMsgId = protocolId;
	conn->m_oIO.hdr.usMsgLen =  buffer.size();

	conn->m_oIO.type = IO_WRITE_HEAD;

	ZeroMemory( conn->m_oIO.buffer, BUFFER_SIZE );
	memcpy( conn->m_oIO.buffer, buffer.c_str(),  buffer.size() );

	conn->AsyncSendHead();

	//PostQueuedCompletionStatus( m_pNetworkSrv->getCompletePortHandle(), 0, (DWORD)conn, &conn->m_oIO.overlapped );

	//conn->m_oIO.buffer = (char*)buffer.c_str();

}