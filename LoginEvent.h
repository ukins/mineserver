#pragma once
#include "BaseEvent.h"
/*
	��¼ģ������Զ����¼���, �¼�����Id [10000~11000);
*/
class LoginEvent :
	public CBaseEvent
{
public:
	LoginEvent( unsigned int id ) :CBaseEvent( id ){};
	~LoginEvent(){};

public:
	//��¼�ɹ�
	static const unsigned LOGIN_SUCCESS = 10000;

	//��¼ʧ��
	static const unsigned LOGIN_FAILED = 10001;
};

