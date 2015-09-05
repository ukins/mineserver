#pragma once
#include <WinSock2.h>
#include <string>

class NetworkModule;
class CConnect
{
public:
	CConnect( const SOCKET sClient, const sockaddr_in & addrClient );
	virtual ~CConnect();

public:
	bool	IsConning( void ){
		return m_bConning;
	}

	void	DisConning( void ){
		m_bConning = false;
	}

	bool	IsExit( void ){
		return m_bExit;
	}

	bool	AsyncRecvHead( void );				//接收包头
	bool	AsyncRecvBody( void );				//接收包体
	bool	AsyncSendHead( void );				//发送包头
	bool	AsyncSendBody( void );				//发送包体

	void	OnRecvHeadCompleted( DWORD dwIOSize );	//接收包头完成
	void	OnRecvBodyCompleted( DWORD dwIOSize );	//接收包体完成
	void	OnSendHeadCompleted( DWORD dwIOSize );	//发送包头完成
	void	OnSendBodyCompleted( DWORD dwIOSize );	//发送包体完成

	SOCKET	getSocket()
	{
		return m_socket;
	}

public:
	IO_OPERATION_DATA	m_iIO;		//读扩展重叠结构数据结构
	IO_OPERATION_DATA	m_oIO;		//写扩展重叠结构数据结构

private:
	SOCKET		m_socket;		//套接字
	sockaddr_in	m_addr;			//地址

	bool		m_bConning;		//客户端连接状态
	bool		m_bExit;		//线程退出

	std::string		m_str;			//收发的数据

	NetworkModule* m_pNetworkModule;	//保存一个Network模块的指针

};

