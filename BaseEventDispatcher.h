#pragma once
#include <map>
#include <list>
#include "BaseEvent.h"
#include "IBaseDelegate.h"

/*
	�¼�������
*/
class CBaseEventDispatcher
{
	//�¼��ص�ί�еļ�������
	using EventMap = std::map < unsigned int, std::list<IBaseDelegate*> >;

public:
	CBaseEventDispatcher();
	~CBaseEventDispatcher();

public:
	//ע�������¼�����������¼�¼�������ص�����
	virtual void Register( unsigned int evtId, IBaseDelegate* p_delegate );

	//�Ƴ�������¼�������
	virtual void UnRegister( unsigned int evtId, IBaseDelegate* p_delegate );

	//�����¼����͵�ID���¼�����֪ͨ
	virtual void dispatchEvent( const CBaseEvent& evt );

protected:

	EventMap	m_eventmap;
};

