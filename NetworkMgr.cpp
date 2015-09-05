#include "stdafx.h"
#include "NetworkMgr.h"
#include "TimeTicker.h"

CNetworkMgr::CNetworkMgr()
{
}
CNetworkMgr::~CNetworkMgr()
{
}

/*
* ��ʼ��
*/
bool CNetworkMgr::Init()
{
	if (!InitMember())
	{
		return false;
	}

	if (!InitSocket())
	{
		return false;
	}

	return true;
}

/*
* ����
*/
bool CNetworkMgr::Startup()
{
	if ( !StartupThread() )
	{
		return false;
	}
	return true;
}

/*
* ֹͣ
*/
bool CNetworkMgr::Stop()
{
	m_bRunning = FALSE;//����������״̬

	H_THREAD_VECT::size_type len = m_vecThread.size();
	for ( decltype(len) i = 0; i < len; i++ )
	{
		//CloseHandle( m_vecThread[i] );//�ر����߳̾��
		if ( i < len - 1 )
		{
			//������̷߳����˳�֪ͨ
			PostQueuedCompletionStatus( m_hCompPort, 0, (DWORD)NULL, NULL );
		}
	}


	HANDLE *ph = new HANDLE[len];

	for ( decltype(len) i = 0; i < len; ++i )
	{
		ph[i] = m_vecThread[i];
	}

	//�ȴ����߳��˳�
	::WaitForMultipleObjects( len, ph, TRUE, INFINITE );

	for ( decltype(len) i = 0; i < len; i++ )
	{
		CloseHandle( m_vecThread[i] );//�ر����߳̾��
	}

	delete[] ph;

	printf( "============NetworkMgr Stop Succeed!\n" );

	return true;
}

/*
* �˳�
*/
void CNetworkMgr::Exit()
{
	closesocket( m_socket );		//�رռ����׽���
	WSACloseEvent( m_hEvent );	//�ر��¼�
	WSACleanup();				//�ͷ��׽�����Դ
	CloseHandle( m_hCompPort );	//�ر���ɶ˿�
}

bool CNetworkMgr::InitMember()
{
	m_socket = INVALID_SOCKET;
	m_bRunning = false;
	m_vecThread.clear();

	return true;
}

bool CNetworkMgr::InitSocket()
{
	WSADATA	wsaData;
	int retVal;

	if ( WSAStartup( MAKEWORD( 2, 2 ), &wsaData ) != 0 )
	{
		ShowErrorMsg( "WSAStartup() failed!\n" );
		return false;
	}

	if ( LOBYTE( wsaData.wVersion ) != 2 || HIBYTE( wsaData.wVersion ) != 2 )
	{
		ShowErrorMsg( "WinSock Dll version is wrong!\n" );
		WSACleanup();
		return false;
	}

	if ( (m_socket = WSASocket( AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED )) == INVALID_SOCKET )
	{
		ShowErrorMsg( "WSASocket() failed!\n" );
		WSACleanup();
		return false;
	}

	sockaddr_in	addrServ;
	addrServ.sin_family = AF_INET;
	addrServ.sin_port = htons( PORT );
	addrServ.sin_addr.S_un.S_addr = inet_addr( "192.168.1.102" );

	retVal = bind( m_socket, (LPSOCKADDR)&addrServ, sizeof( addrServ ) );
	if (SOCKET_ERROR == retVal)
	{
		ShowErrorMsg( "bind() failed!\n" );
		closesocket( m_socket );
		WSACleanup();
		return false;
	}

	retVal = listen( m_socket, SOMAXCONN );
	if ( SOCKET_ERROR == retVal )
	{
		ShowErrorMsg( "listen() failed!\n" );
		closesocket( m_socket );
		WSACleanup();
		return false;
	}

	printf( "Server startup succeed!\n" );

	return true;
}

void CNetworkMgr::ShowErrorMsg( char* str )
{
	//MessageBox( NULL, str, "ERROR", MB_OK );
}

bool	CNetworkMgr::StartupThread( void )
{
	m_bRunning = true;

	//�������ܿͻ��������¼�����
	m_hEvent = WSACreateEvent();
	if ( m_hEvent == WSA_INVALID_EVENT )
	{
		closesocket( m_socket );
		WSACleanup();
		return false;
	}

	//Ϊ�����׽���ע��FD_ACCEPT�����¼�
	int retVal = WSAEventSelect( m_socket, m_hEvent, FD_ACCEPT );
	if ( retVal == SOCKET_ERROR )
	{
		ShowErrorMsg( "WSAEventSelect() failed!" );
		closesocket( m_socket );
		WSACleanup();
		return false;
	}

	//������ɶ˿�
	m_hCompPort = CreateIoCompletionPort( INVALID_HANDLE_VALUE, NULL, 0, 0 );
	if ( m_hCompPort == NULL )
	{
		ShowErrorMsg( "CreateIoCompletionPort() failed!" );
		WSACloseEvent( m_hEvent );
		closesocket( m_socket );
		WSACleanup();
		return false;
	}

	//�������ܿͻ��������߳�
	DWORD dwThreadID;
	HANDLE	hthread;
	hthread = CreateThread( NULL, 0, AcceptThread, this, 0, &dwThreadID );
	if ( NULL == hthread )
	{
		ShowErrorMsg( "Create AcceptThread failed��" );
		WSACloseEvent( m_hEvent );
		closesocket( m_socket );
		WSACleanup();
		return false;
	}
	else
	{
		m_vecThread.push_back( hthread );
	}

	SYSTEM_INFO SystemInfo;
	GetSystemInfo( &SystemInfo );

	for ( size_t i = 0; i < SystemInfo.dwNumberOfProcessors * 2; ++i )
	{
		hthread = CreateThread( NULL, 0, ServiceThread, this, 0, &dwThreadID );
		if ( NULL == hthread )
		{
			ShowErrorMsg( "Create ServiceThread failed��" );
			WSACloseEvent( m_hEvent );
			closesocket( m_socket );
			WSACleanup();
			return false;
		}
		else
		{
			m_vecThread.push_back( hthread );
		}
	}


	return true;
}

DWORD WINAPI CNetworkMgr::AcceptThread( void *pParam )
{
	CNetworkMgr *pNetworkSrv = (CNetworkMgr *)pParam;

	HANDLE	hComPort = pNetworkSrv->m_hCompPort;	//��ɶ˿�
	SOCKET	sListen = pNetworkSrv->m_socket;		//�����׽���

	SOCKET	sAccept = INVALID_SOCKET;				//���ܿͻ������ӵ��׽���
	//sockaddr_in	addrClient;		//�ͻ���SOCKET��ַ

	while ( pNetworkSrv->m_bRunning )
	{
		DWORD dwRet;
		dwRet = WSAWaitForMultipleEvents( 1, &pNetworkSrv->m_hEvent, FALSE, 100, FALSE );	//�ȴ������¼�

		if ( !pNetworkSrv->m_bRunning )				//������ֹͣ����
		{
			break;
		}

		if ( dwRet == WSA_WAIT_TIMEOUT )			//�������ó�ʱ
		{
			continue;
		}

		WSANETWORKEVENTS events;
		int nRet = WSAEnumNetworkEvents( pNetworkSrv->m_socket, pNetworkSrv->m_hEvent, &events );

		if ( SOCKET_ERROR == nRet )
		{
			pNetworkSrv->ShowErrorMsg( "WSAEnumNetworkEvents() failed!\n" );
			break;
		}

		if ( events.lNetworkEvents & FD_ACCEPT )
		{
			if ( events.iErrorCode[FD_ACCEPT_BIT] == 0 && pNetworkSrv->m_bRunning)
			{
				sockaddr_in addrClient;
				int addrClientLen = sizeof( addrClient );
				sAccept = WSAAccept( sListen, (LPSOCKADDR)&addrClient, &addrClientLen, NULL, 0 );
				if ( INVALID_SOCKET == sAccept )
				{
					pNetworkSrv->ShowErrorMsg( "WSAAccept() failed!\n" );
					break;
				}

				CConnect *pConnect = new CConnect( sAccept, addrClient );

				if ( CreateIoCompletionPort( (HANDLE)sAccept, hComPort, (DWORD)pConnect, 0 ) == NULL )
				{
					return -1;
				}

				//�������ͻ�������
				CConnectMgr *pConnectMgr = CConnectMgr::GetInstance();
				pConnectMgr->AddConnect( pConnect );
				if ( !pConnect->AsyncRecvHead() )
				{
					pConnectMgr->DeleteConnect( pConnect );
				}

			}
		}
		
	}

	//�ͷ���Դ
	CConnectMgr *pConnectMgr = CConnectMgr::GetInstance();
	pConnectMgr->DeleteAllConnect();
	pConnectMgr->Release();

	//Sleep( 10000 );
	printf( "AcceptThread return\n" );

	return 0;
}


DWORD WINAPI CNetworkMgr::ServiceThread( void *pParam )
{
	CNetworkMgr *pNetworkSrv = (CNetworkMgr *)pParam;

	HANDLE	hComPort = pNetworkSrv->m_hCompPort;

	DWORD			dwIoSize;			//������ֽ���
	CConnect*		pConnect;			//�ͻ���ָ��
	LPOVERLAPPED	lpOverlapped;		//�ص��ṹָ��
	bool			bExit = false;		//�����߳��˳�

	while ( !bExit )
	{
		dwIoSize = -1;
		lpOverlapped = nullptr;
		pConnect = nullptr;

		BOOL bIORet = GetQueuedCompletionStatus( hComPort,
												&dwIoSize,
												(PULONG_PTR)&pConnect,
												&lpOverlapped,
												TIMEFOR_THREAD_HELP );

		//ʧ�ܵĲ������
		if ( FALSE == bIORet )
		{
			DWORD dwIOError = WSAGetLastError();
			if ( dwIOError == WSA_WAIT_TIMEOUT )
			{
				continue;
			}
			else if ( NULL != lpOverlapped )
			{
				CConnectMgr *pConnectMgr = CConnectMgr::GetInstance();
				pConnectMgr->DeleteConnect( pConnect );
			}
			else
			{
				//printf()
				break;	//�˳�
			}
		}
		//�ɹ��Ĳ������
		if ( TRUE == bIORet && lpOverlapped && pConnect )
		{
			CConnectMgr *pConnectMgr = CConnectMgr::GetInstance();
			pConnectMgr->ProcessIO( pConnect, lpOverlapped, dwIoSize );
		}
		//���߳�����������
		if ( TRUE == bIORet && lpOverlapped == nullptr && pConnect )
		{
			//pClient->AsyncSend();
		}

		//�������˳�
		if ( pConnect == NULL && lpOverlapped == NULL && !pNetworkSrv->m_bRunning )
		{
			bExit = TRUE;
		}
	}

	//Sleep( 10000 );

	printf( "ServiceThread return\n" );

	return 0;

}