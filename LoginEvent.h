#pragma once
#include "BaseEvent.h"
/*
	登录模块相关自定义事件类, 事件类型Id [10000~11000);
*/
class LoginEvent :
	public CBaseEvent
{
public:
	LoginEvent( unsigned int id ) :CBaseEvent( id ){};
	~LoginEvent(){};

public:
	//登录成功
	static const unsigned LOGIN_SUCCESS = 10000;

	//登录失败
	static const unsigned LOGIN_FAILED = 10001;
};

