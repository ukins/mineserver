#pragma once
#include <map>
#include "Connect.h"

class CConnectMgr
{
	using CONNECT_MAP = std::map < SOCKET, CConnect * > ;

public:
	virtual ~CConnectMgr();

public:
	static CConnectMgr *GetInstance( void );
	static void Release( void );			//释放客户端链接管理对象资源

	void	ProcessIO( CConnect *pConnect, LPOVERLAPPED pOverlapped, DWORD dwIOSize );
	void	AddConnect( CConnect *pConnect );	//增加客户端链接
	void	DeleteConnect( CConnect *pConnect );	//删除客户端链接
	void	DeleteAllConnect( void );			//删除所有客户端链接
	CConnect * GetConnectBySocket(SOCKET s);			//根据Socket获取一个客户端链接

private:
	CConnectMgr();
	//CConnectMgr( const CConnectMgr& other );
	//CConnectMgr& operator= (CConnectMgr& other);
	static CConnectMgr *m_pConnectMgr;

	CRITICAL_SECTION	m_cs;
	CONNECT_MAP			m_connects;			//客户端链接容器

};

