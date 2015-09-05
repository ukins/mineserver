#pragma once
#include "BaseEvent.h"
/*
	网络模块相关事件类，事件类型Id[2000~3000) : CTimeEvent[1000~2000)
*/
class NetworkEvent :
	public CBaseEvent
{
public:
	NetworkEvent( unsigned id ) :CBaseEvent( id ){};
	~NetworkEvent(){};

public:
	//网络模块安装失败事件
	static const unsigned INSTALL_FAIL = 2000;


	static const unsigned RECV_PACKAGE = 2001;

};

