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

	//static CNetworkSrv *GetInstance( void );		//��ȡ����

	bool	Init( void );				//��ʼ��
	bool	Startup( void );			//��������
	bool	Stop( void );				//ֹͣ����
	void	Exit( void );				//�˳�

	HANDLE getCompletePortHandle()
	{
		return m_hCompPort;
	}

private:
	//static CNetworkSrv *m_pNetwork;

	bool	InitMember( void );			//��ʼ��ȫ�ֱ���
	bool	InitSocket( void );			//��ʼ���׽���

	void	ShowErrorMsg( char* str );	

	bool	StartupThread( void );	//�����߳�

	static DWORD WINAPI ServiceThread( void *pParam );	//�ͷ���Դ
	static DWORD WINAPI AcceptThread( void *pParam );	//���ܿͻ��������߳�


	//const char* IP = "127.0.0.1";		
	const short	PORT = 5000;			//�����˿�

	const static int TIMEFOR_THREAD_EXIT = 5000;	//���߳�˯��ʱ��
	const static int TIMEFOR_THREAD_HELP = 1500;	//������Դ�߳��˳�ʱ��
	const static int TIMEFOR_THREAD_SLEEP = 500;	//�ȴ��ͻ��������߳�˯��ʱ��
	const static int TIMEFOR_WAIT_IO = 20;			//�ȴ�IOʱ��

	SOCKET				m_socket;		//�����׽���
	bool				m_bRunning;		//����������״̬
	HANDLE				m_hEvent;		//�����¼����
	HANDLE				m_hCompPort;	//��ɶ˿ھ��
	H_THREAD_VECT		m_vecThread;	//�߳̾��

};

