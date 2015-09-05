#include "stdafx.h"
#include "ConnectMgr.h"

CConnectMgr *CConnectMgr::m_pConnectMgr = nullptr;
CConnectMgr::CConnectMgr()
{
	m_pConnectMgr = nullptr;

	InitializeCriticalSection( &m_cs );
}


CConnectMgr::~CConnectMgr()
{
	DeleteCriticalSection( &m_cs );
}

CConnectMgr *CConnectMgr::GetInstance()
{
	if ( m_pConnectMgr == nullptr )
	{
		m_pConnectMgr = new CConnectMgr;
	}
	return m_pConnectMgr;
}

void CConnectMgr::AddConnect( CConnect *pConnect )
{
	EnterCriticalSection( &m_cs );

	m_connects.insert( { pConnect->getSocket(), pConnect } );

	LeaveCriticalSection( &m_cs );
}

void CConnectMgr::DeleteConnect( CConnect *pConnect )
{
	EnterCriticalSection( &m_cs );

	CConnect *p = m_connects[pConnect->getSocket()];
	m_connects.erase( pConnect->getSocket() );
	if ( p != nullptr )
	{
		delete p;
		p = nullptr;
	}

	LeaveCriticalSection( &m_cs );
}

void CConnectMgr::DeleteAllConnect()
{
	EnterCriticalSection( &m_cs );

	for ( auto &w : m_connects )
	{
		CConnect *p = w.second;
		if ( p != nullptr )
		{
			delete p;
			p = nullptr;
		}
	}
	m_connects.clear();

	LeaveCriticalSection( &m_cs );
}

CConnect * CConnectMgr::GetConnectBySocket( SOCKET s )
{
	//EnterCriticalSection( &m_cs );

	auto iter = m_connects.find( s );
	if ( iter == m_connects.end() )
	{
		printf( "CConnectMgr::GetConnectBySocket Failed!!!!!!" );
		return nullptr;
	}
	else
	{
		return iter->second;
	}

	//LeaveCriticalSection( &m_cs );
}
void CConnectMgr::Release()
{
	if ( nullptr != m_pConnectMgr )
	{
		delete m_pConnectMgr;
		m_pConnectMgr = nullptr;
	}
}

void CConnectMgr::ProcessIO( CConnect *pConnect, LPOVERLAPPED pOverlapped, DWORD dwIOSize )
{
	//获取扩展重叠结构指针
	PIO_OPERATION_DATA pIO = CONTAINING_RECORD( pOverlapped, IO_OPERATION_DATA, overlapped );


	if ( NULL != pIO )
	{
		switch ( pIO->type )
		{
		case IO_READ_HEAD:
		{
			pConnect->OnRecvHeadCompleted( dwIOSize );
			break;
		}
		case IO_READ_BODY:
		{
			pConnect->OnRecvBodyCompleted( dwIOSize );
			break;
		}
		case IO_WRITE_HEAD:
		{
			pConnect->OnSendHeadCompleted( dwIOSize );
			break;
		}
		case IO_WRITE_BODY:
		{
			pConnect->OnSendBodyCompleted( dwIOSize );
		}
		default:
			break;
		}
	}
}