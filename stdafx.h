// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>

#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

#define		RECV_SIZE			64		//每次接收数据包的字节数
#define		BUFFER_SIZE	65536	//缓冲区大小

#define		HEADER_LEN			(sizeof(HDR))				//包头长度
#define		OVERLAPPED_LEN		(sizeof(IO_OPERATION_DATA))	//扩展重叠结构长度

#define		IO_READ_HEAD		11		//接受包头
#define		IO_READ_BODY		12		//接受包体
#define		IO_WRITE_HEAD		13		//发送消息头
#define		IO_WRITE_BODY		14		//发送消息体

//#define		IO_COMPLETED		21		//包读取完全
//#define		IO_UNCOMPLETE		22		//包未读取完全

//包头
typedef struct _header
{
	u_short		usMsgLen;	//包体长度
	u_short		usMsgId;	//包ID
}HDR, *PHDR;

typedef struct _io_operation_data
{
	OVERLAPPED	overlapped;
	WSABUF		dataBuf;
	CHAR		buffer[BUFFER_SIZE];
	HDR			hdr;
	byte		type;		//操作类型
	u_short		usIOSize;	//
}IO_OPERATION_DATA, *PIO_OPERATION_DATA;

//从IO抛向业务层的数据结构
typedef struct io_complete_data
{
	SOCKET usClientSocket;	//客户端连接
	u_short usMsgId;		//协议Id
	char * buffer;			//一个完整数据包的包体 使用_strdup所得，需调用free;
}IO_COMPLETE_DATA, *PIO_COMPLETE_DATA;//从IO抛向业务层的数据结构


// TODO:  在此处引用程序需要的其他头文件
