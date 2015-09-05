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
	static void Release( void );			//�ͷſͻ������ӹ��������Դ

	void	ProcessIO( CConnect *pConnect, LPOVERLAPPED pOverlapped, DWORD dwIOSize );
	void	AddConnect( CConnect *pConnect );	//���ӿͻ�������
	void	DeleteConnect( CConnect *pConnect );	//ɾ���ͻ�������
	void	DeleteAllConnect( void );			//ɾ�����пͻ�������
	CConnect * GetConnectBySocket(SOCKET s);			//����Socket��ȡһ���ͻ�������

private:
	CConnectMgr();
	//CConnectMgr( const CConnectMgr& other );
	//CConnectMgr& operator= (CConnectMgr& other);
	static CConnectMgr *m_pConnectMgr;

	CRITICAL_SECTION	m_cs;
	CONNECT_MAP			m_connects;			//�ͻ�����������

};

