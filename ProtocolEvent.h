#pragma once
#include "BaseEvent.h"
/*
	�߼���Э��ģ������¼��࣬�¼�����Id[3000~4000) : NetworkEvent[2000~3000)
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

