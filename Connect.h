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

	bool	AsyncRecvHead( void );				//���հ�ͷ
	bool	AsyncRecvBody( void );				//���հ���
	bool	AsyncSendHead( void );				//���Ͱ�ͷ
	bool	AsyncSendBody( void );				//���Ͱ���

	void	OnRecvHeadCompleted( DWORD dwIOSize );	//���հ�ͷ���
	void	OnRecvBodyCompleted( DWORD dwIOSize );	//���հ������
	void	OnSendHeadCompleted( DWORD dwIOSize );	//���Ͱ�ͷ���
	void	OnSendBodyCompleted( DWORD dwIOSize );	//���Ͱ������

	SOCKET	getSocket()
	{
		return m_socket;
	}

public:
	IO_OPERATION_DATA	m_iIO;		//����չ�ص��ṹ���ݽṹ
	IO_OPERATION_DATA	m_oIO;		//д��չ�ص��ṹ���ݽṹ

private:
	SOCKET		m_socket;		//�׽���
	sockaddr_in	m_addr;			//��ַ

	bool		m_bConning;		//�ͻ�������״̬
	bool		m_bExit;		//�߳��˳�

	std::string		m_str;			//�շ�������

	NetworkModule* m_pNetworkModule;	//����һ��Networkģ���ָ��

};

