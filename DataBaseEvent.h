#pragma once
#include "BaseEvent.h"
/*
	���ݿ�����¼� �¼�����Id[4000~5000) : ProtocolEvent[3000~4000)
*/
class DataBaseEvent :
	public CBaseEvent
{
public:
	DataBaseEvent( unsigned int id ) :CBaseEvent( id ){};
	~DataBaseEvent(){};

public:
	static const unsigned int COMPLETE = 4000;
};

