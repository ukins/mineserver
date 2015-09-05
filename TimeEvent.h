#pragma once
#include "BaseEvent.h"
/*
	时间相关事件类, 事件类型Id [1000~2000): CBaseEvent[0~1000);
*/
class CTimeEvent :
	public CBaseEvent
{
public:
	CTimeEvent( unsigned int id ) :CBaseEvent( id ){};
	~CTimeEvent(){};

public:
	//自定时器启动之后，每20毫秒触发一次的时间事件
	static const unsigned MILLISECOND_20 = 1000;

	//自定时器启动之后，每100毫秒触发一次的时间事件
	//static const unsigned MILLISECOND_100 = 1001;

	//自定时器启动之后，每秒钟触发一次的时间事件
	static const unsigned SECOND = 1002;

	//自定时器启动之后，每分钟触发一次的时间事件
	static const unsigned MUNITE = 1003;

	//自定时器启动之后，每小时触发一次的时间事件
	//static const unsigned HOUR = 1004;

	//自定时器启动之后，整点触发的时间事件（根据服务器时间判断当前是否整点，如是，则触发事件）
	//static const unsigned WHOLE_POINT = 1005;

};

