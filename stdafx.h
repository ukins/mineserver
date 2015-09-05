// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>

#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

#define		RECV_SIZE			64		//ÿ�ν������ݰ����ֽ���
#define		BUFFER_SIZE	65536	//��������С

#define		HEADER_LEN			(sizeof(HDR))				//��ͷ����
#define		OVERLAPPED_LEN		(sizeof(IO_OPERATION_DATA))	//��չ�ص��ṹ����

#define		IO_READ_HEAD		11		//���ܰ�ͷ
#define		IO_READ_BODY		12		//���ܰ���
#define		IO_WRITE_HEAD		13		//������Ϣͷ
#define		IO_WRITE_BODY		14		//������Ϣ��

//#define		IO_COMPLETED		21		//����ȡ��ȫ
//#define		IO_UNCOMPLETE		22		//��δ��ȡ��ȫ

//��ͷ
typedef struct _header
{
	u_short		usMsgLen;	//���峤��
	u_short		usMsgId;	//��ID
}HDR, *PHDR;

typedef struct _io_operation_data
{
	OVERLAPPED	overlapped;
	WSABUF		dataBuf;
	CHAR		buffer[BUFFER_SIZE];
	HDR			hdr;
	byte		type;		//��������
	u_short		usIOSize;	//
}IO_OPERATION_DATA, *PIO_OPERATION_DATA;

//��IO����ҵ�������ݽṹ
typedef struct io_complete_data
{
	SOCKET usClientSocket;	//�ͻ�������
	u_short usMsgId;		//Э��Id
	char * buffer;			//һ���������ݰ��İ��� ʹ��_strdup���ã������free;
}IO_COMPLETE_DATA, *PIO_COMPLETE_DATA;//��IO����ҵ�������ݽṹ


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
