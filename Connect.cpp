#include "stdafx.h"
#include "ModuleMgr.h"
#include "NetworkModule.h"
#include "Connect.h"

CConnect::CConnect( const SOCKET sClient, const sockaddr_in & addrClient )
{
	m_socket = sClient;
	m_addr = addrClient;
	ZeroMemory( &m_iIO, sizeof( m_iIO ) );
	ZeroMemory( &m_oIO, sizeof( m_oIO ) );

	m_pNetworkModule = (NetworkModule*)ModuleMgr::getInstance()->getModuleById( NetworkModule::getStaticModuleId() );
}


CConnect::~CConnect()
{
	closesocket( m_socket );
	m_socket = INVALID_SOCKET;
}

/*
* �첽���հ�ͷ
*/
bool CConnect::AsyncRecvHead()
{
	DWORD	flags = 0;
	DWORD	recvBytes = 0;

	m_iIO.type = IO_READ_HEAD;

	m_iIO.dataBuf.buf = (char *)&m_iIO.hdr + m_iIO.usIOSize;
	m_iIO.dataBuf.len = HEADER_LEN - m_iIO.usIOSize;

	if ( WSARecv( m_socket, &m_iIO.dataBuf, 1, &recvBytes, &flags, &m_iIO.overlapped, NULL ) == SOCKET_ERROR )
	{
		if ( ERROR_IO_PENDING != WSAGetLastError() )
		{
			return false;
		}
	}

	return true;
}

/*
* ���հ�ͷ
*/
void CConnect::OnRecvHeadCompleted( DWORD dwIOSize )
{
	m_iIO.usIOSize += (u_short)dwIOSize;
	if ( m_iIO.usIOSize < HEADER_LEN )	//��ͷ��ȡ������������������壻����������������ͷ
	{
		AsyncRecvHead();
	}
	else
	{
		m_iIO.usIOSize = 0;
		AsyncRecvBody();
	}
}

/*
* �첽���ܰ���
*/
bool CConnect::AsyncRecvBody()
{
	DWORD	flags = 0;
	DWORD	recvBytes = 0;

	//ZeroMemory( &m_iIO, sizeof( m_iIO ) );
	m_iIO.type = IO_READ_BODY;

	m_iIO.dataBuf.buf = m_iIO.buffer + m_iIO.usIOSize;
	u_short diff = m_iIO.hdr.usMsgLen - m_iIO.usIOSize;
	m_iIO.dataBuf.len = RECV_SIZE > diff ? diff : RECV_SIZE;

	if ( WSARecv( m_socket, &m_iIO.dataBuf, 1, &recvBytes, &flags, &m_iIO.overlapped, NULL ) == SOCKET_ERROR )
	{
		if ( ERROR_IO_PENDING != WSAGetLastError() )
		{
			return false;
		}
	}

	return true;
}

/*
* ���հ���
*/
void CConnect::OnRecvBodyCompleted( DWORD dwIOSize )
{
	m_iIO.usIOSize += (u_short)dwIOSize;

	if ( m_iIO.usIOSize < m_iIO.hdr.usMsgLen )	//�����ȡ�Ƿ�����
	{
		AsyncRecvBody();
	}
	else
	{
		DWORD dwCurrThreadID = GetCurrentThreadId();
		//�����߳��׳����ݰ�
		IO_COMPLETE_DATA* p_syncData = new IO_COMPLETE_DATA;
		p_syncData->usClientSocket = this->getSocket();
		p_syncData->usMsgId = m_iIO.hdr.usMsgId;

		char *buffer = (char*)malloc( sizeof( char )*(m_iIO.hdr.usMsgLen+1) );
		memset( buffer, 0, m_iIO.hdr.usMsgLen+1 );
		memcpy( buffer, m_iIO.buffer, m_iIO.hdr.usMsgLen );
		buffer[m_iIO.hdr.usMsgLen] = '\0';

		p_syncData->buffer = buffer;
		
		NetworkEvent networkEvt( p_syncData->usMsgId );
		networkEvt.m_pArgs = p_syncData;

		/*m_str = m_iIO.buffer;
		printf( "%s.  len =%d\n", m_str.c_str(), strlen( m_str.c_str() ) );*/

		//�˷���Ϊ�߼���Ψһ��ڣ��Դ�ͬ�����ƣ�
		m_pNetworkModule->dispatchEvent( networkEvt );
		
		//Sleep( 1000 );	//������

		m_iIO.usIOSize = 0;
		AsyncRecvHead();
	}

}

bool CConnect::AsyncSendHead( void )
{
	DWORD	flags = 0;			//��־
	DWORD	sendBytes = 0;		//�����ֽ���

	m_oIO.type = IO_WRITE_HEAD;

	m_oIO.dataBuf.buf = (char*)&m_oIO.hdr + m_oIO.usIOSize;
	m_oIO.dataBuf.len = HEADER_LEN - m_oIO.usIOSize;

	if ( WSASend( m_socket, &m_oIO.dataBuf, 1, &sendBytes, flags, &m_oIO.overlapped, NULL ) == SOCKET_ERROR )
	{
		if ( ERROR_IO_PENDING != WSAGetLastError() )
		{
			return false;
		}
	}

	return true;

}


void CConnect::OnSendHeadCompleted( DWORD dwIOSize )
{
	m_oIO.usIOSize += (u_short)dwIOSize;

	if ( m_oIO.usIOSize < HEADER_LEN )
	{
		AsyncSendHead();
	}
	else
	{
		m_oIO.usIOSize = 0;
		AsyncSendBody();
	}

}

bool CConnect::AsyncSendBody( void )
{
	DWORD	flags = 0;			//��־
	DWORD	sendBytes = 0;		//�����ֽ���

	m_oIO.type = IO_WRITE_BODY;

	m_oIO.dataBuf.buf = m_oIO.buffer + m_oIO.usIOSize;
	m_oIO.dataBuf.len = m_oIO.hdr.usMsgLen - m_oIO.usIOSize;

	if ( WSASend( m_socket, &m_oIO.dataBuf, 1, &sendBytes, flags, &m_oIO.overlapped, NULL ) == SOCKET_ERROR )
	{
		if ( ERROR_IO_PENDING != WSAGetLastError() )
		{
			return false;
		}
	}

	return true;
}

void CConnect::OnSendBodyCompleted( DWORD dwIOSize )
{
	m_oIO.usIOSize += (u_short)dwIOSize;

	if ( m_oIO.usIOSize < m_oIO.hdr.usMsgLen )
	{
		AsyncSendBody();
	}
	else
	{
		//������ɣ�
		printf( "Send Complete\n" );
	}
}
