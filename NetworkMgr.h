#pragma once
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

#include <list>
#include <vector>

#include "Connect.h"
#include "ConnectMgr.h"

#include "LockList.h"


class CNetworkMgr
{
	using H_THREAD_VECT = std::vector < HANDLE > ;
public:
	virtual ~CNetworkMgr();

public:
	CNetworkMgr();
	//CNetworkSrv( const CNetworkSrv& other );
	//CNetworkSrv& operator = (CNetworkSrv& other);

	//static CNetworkSrv *GetInstance( void );		//获取单例

	bool	Init( void );				//初始化
	bool	Startup( void );			//启动服务
	bool	Stop( void );				//停止服务
	void	Exit( void );				//退出

	HANDLE getCompletePortHandle()
	{
		return m_hCompPort;
	}

private:
	//static CNetworkSrv *m_pNetwork;

	bool	InitMember( void );			//初始化全局变量
	bool	InitSocket( void );			//初始化套接字

	void	ShowErrorMsg( char* str );	

	bool	StartupThread( void );	//创建线程

	static DWORD WINAPI ServiceThread( void *pParam );	//释放资源
	static DWORD WINAPI AcceptThread( void *pParam );	//接受客户端连接线程


	//const char* IP = "127.0.0.1";		
	const short	PORT = 5000;			//监听端口

	const static int TIMEFOR_THREAD_EXIT = 5000;	//主线程睡眠时间
	const static int TIMEFOR_THREAD_HELP = 1500;	//清理资源线程退出时间
	const static int TIMEFOR_THREAD_SLEEP = 500;	//等待客户端请求线程睡眠时间
	const static int TIMEFOR_WAIT_IO = 20;			//等待IO时间

	SOCKET				m_socket;		//监听套接字
	bool				m_bRunning;		//服务器运行状态
	HANDLE				m_hEvent;		//监听事件句柄
	HANDLE				m_hCompPort;	//完成端口句柄
	H_THREAD_VECT		m_vecThread;	//线程句柄

};

