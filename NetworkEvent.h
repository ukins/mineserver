#pragma once
#include "BaseEvent.h"
/*
	����ģ������¼��࣬�¼�����Id[2000~3000) : CTimeEvent[1000~2000)
*/
class NetworkEvent :
	public CBaseEvent
{
public:
	NetworkEvent( unsigned id ) :CBaseEvent( id ){};
	~NetworkEvent(){};

public:
	//����ģ�鰲װʧ���¼�
	static const unsigned INSTALL_FAIL = 2000;


	static const unsigned RECV_PACKAGE = 2001;

};

