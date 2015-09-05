#pragma once
#include "BaseEvent.h"
/*
	ʱ������¼���, �¼�����Id [1000~2000): CBaseEvent[0~1000);
*/
class CTimeEvent :
	public CBaseEvent
{
public:
	CTimeEvent( unsigned int id ) :CBaseEvent( id ){};
	~CTimeEvent(){};

public:
	//�Զ�ʱ������֮��ÿ20���봥��һ�ε�ʱ���¼�
	static const unsigned MILLISECOND_20 = 1000;

	//�Զ�ʱ������֮��ÿ100���봥��һ�ε�ʱ���¼�
	//static const unsigned MILLISECOND_100 = 1001;

	//�Զ�ʱ������֮��ÿ���Ӵ���һ�ε�ʱ���¼�
	static const unsigned SECOND = 1002;

	//�Զ�ʱ������֮��ÿ���Ӵ���һ�ε�ʱ���¼�
	static const unsigned MUNITE = 1003;

	//�Զ�ʱ������֮��ÿСʱ����һ�ε�ʱ���¼�
	//static const unsigned HOUR = 1004;

	//�Զ�ʱ������֮�����㴥����ʱ���¼������ݷ�����ʱ���жϵ�ǰ�Ƿ����㣬���ǣ��򴥷��¼���
	//static const unsigned WHOLE_POINT = 1005;

};

