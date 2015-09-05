#pragma once
#include <map>
#include <list>
#include "BaseEvent.h"
#include "IBaseDelegate.h"

/*
	事件触发器
*/
class CBaseEventDispatcher
{
	//事件回调委托的集合类型
	using EventMap = std::map < unsigned int, std::list<IBaseDelegate*> >;

public:
	CBaseEventDispatcher();
	~CBaseEventDispatcher();

public:
	//注册对相关事件的侦听，记录事件对象与回调函数
	virtual void Register( unsigned int evtId, IBaseDelegate* p_delegate );

	//移除对相关事件的侦听
	virtual void UnRegister( unsigned int evtId, IBaseDelegate* p_delegate );

	//根据事件类型的ID对事件进行通知
	virtual void dispatchEvent( const CBaseEvent& evt );

protected:

	EventMap	m_eventmap;
};

