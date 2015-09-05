#pragma once
#include "BaseEvent.h"
/*
	逻辑层协议模块相关事件类，事件类型Id[3000~4000) : NetworkEvent[2000~3000)
*/
class ProtocolEvent :
	public CBaseEvent
{
public:
	ProtocolEvent( unsigned int id ) :CBaseEvent( id ){};
	~ProtocolEvent(){};

public:
	//static const unsigned CUSTOM_EVENT = 3000;
};

