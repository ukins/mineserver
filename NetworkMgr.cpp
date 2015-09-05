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
* 初始化
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
* 启动
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
* 停止
*/
bool CNetworkMgr::Stop()
{
	m_bRunning = FALSE;//服务器运行状态

	H_THREAD_VECT::size_type len = m_vecThread.size();
	for ( decltype(len) i = 0; i < len; i++ )
	{
		//CloseHandle( m_vecThread[i] );//关闭子线程句柄
		if ( i < len - 1 )
		{
			//向服务线程发送退出通知
			PostQueuedCompletionStatus( m_hCompPort, 0, (DWORD)NULL, NULL );
		}
	}


	HANDLE *ph = new HANDLE[len];

	for ( decltype(len) i = 0; i < len; ++i )
	{
		ph[i] = m_vecThread[i];
	}

	//等待子线程退出
	::WaitForMultipleObjects( len, ph, TRUE, INFINITE );

	for ( decltype(len) i = 0; i < len; i++ )
	{
		CloseHandle( m_vecThread[i] );//关闭子线程句柄
	}

	delete[] ph;

	printf( "============NetworkMgr Stop Succeed!\n" );

	return true;
}

/*
* 退出
*/
void CNetworkMgr::Exit()
{
	closesocket( m_socket );		//关闭监听套接字
	WSACloseEvent( m_hEvent );	//关闭事件
	WSACleanup();				//释放套接字资源
	CloseHandle( m_hCompPort );	//关闭完成端口
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

	//创建接受客户端连接事件对象
	m_hEvent = WSACreateEvent();
	if ( m_hEvent == WSA_INVALID_EVENT )
	{
		closesocket( m_socket );
		WSACleanup();
		return false;
	}

	//为监听套接字注册FD_ACCEPT网络事件
	int retVal = WSAEventSelect( m_socket, m_hEvent, FD_ACCEPT );
	if ( retVal == SOCKET_ERROR )
	{
		ShowErrorMsg( "WSAEventSelect() failed!" );
		closesocket( m_socket );
		WSACleanup();
		return false;
	}

	//创建完成端口
	m_hCompPort = CreateIoCompletionPort( INVALID_HANDLE_VALUE, NULL, 0, 0 );
	if ( m_hCompPort == NULL )
	{
		ShowErrorMsg( "CreateIoCompletionPort() failed!" );
		WSACloseEvent( m_hEvent );
		closesocket( m_socket );
		WSACleanup();
		return false;
	}

	//创建接受客户端请求线程
	DWORD dwThreadID;
	HANDLE	hthread;
	hthread = CreateThread( NULL, 0, AcceptThread, this, 0, &dwThreadID );
	if ( NULL == hthread )
	{
		ShowErrorMsg( "Create AcceptThread failed！" );
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
			ShowErrorMsg( "Create ServiceThread failed！" );
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

	HANDLE	hComPort = pNetworkSrv->m_hCompPort;	//完成端口
	SOCKET	sListen = pNetworkSrv->m_socket;		//监听套接字

	SOCKET	sAccept = INVALID_SOCKET;				//接受客户端连接的套接字
	//sockaddr_in	addrClient;		//客户端SOCKET地址

	while ( pNetworkSrv->m_bRunning )
	{
		DWORD dwRet;
		dwRet = WSAWaitForMultipleEvents( 1, &pNetworkSrv->m_hEvent, FALSE, 100, FALSE );	//等待网络事件

		if ( !pNetworkSrv->m_bRunning )				//服务器停止服务
		{
			break;
		}

		if ( dwRet == WSA_WAIT_TIMEOUT )			//函数调用超时
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

				//加入管理客户端链表
				CConnectMgr *pConnectMgr = CConnectMgr::GetInstance();
				pConnectMgr->AddConnect( pConnect );
				if ( !pConnect->AsyncRecvHead() )
				{
					pConnectMgr->DeleteConnect( pConnect );
				}

			}
		}
		
	}

	//释放资源
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

	DWORD			dwIoSize;			//传输的字节数
	CConnect*		pConnect;			//客户端指针
	LPOVERLAPPED	lpOverlapped;		//重叠结构指针
	bool			bExit = false;		//服务线程退出

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

		//失败的操作完成
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
				break;	//退出
			}
		}
		//成功的操作完成
		if ( TRUE == bIORet && lpOverlapped && pConnect )
		{
			CConnectMgr *pConnectMgr = CConnectMgr::GetInstance();
			pConnectMgr->ProcessIO( pConnect, lpOverlapped, dwIoSize );
		}
		//主线程请求发送数据
		if ( TRUE == bIORet && lpOverlapped == nullptr && pConnect )
		{
			//pClient->AsyncSend();
		}

		//服务器退出
		if ( pConnect == NULL && lpOverlapped == NULL && !pNetworkSrv->m_bRunning )
		{
			bExit = TRUE;
		}
	}

	//Sleep( 10000 );

	printf( "ServiceThread return\n" );

	return 0;

}