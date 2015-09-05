#include "stdafx.h"
#include "BaseEventDispatcher.h"


CBaseEventDispatcher::CBaseEventDispatcher()
{
	m_eventmap.clear();
}


CBaseEventDispatcher::~CBaseEventDispatcher()
{
	for ( auto mapIter = m_eventmap.begin(); mapIter != m_eventmap.end(); )
	{
		auto& lst = (*mapIter).second;
		for ( auto lstIter = lst.begin(); lstIter != lst.end(); ++lstIter )
		{
			delete *lstIter;
		}
		lst.clear();
	}
	m_eventmap.clear();
}


void CBaseEventDispatcher::Register( unsigned int evtId, IBaseDelegate* p_delegate )
{
	auto iter = m_eventmap.find( evtId );
	if ( iter == m_eventmap.end() )		//û���ҵ�����¼�����������
	{
		m_eventmap[evtId] = std::list<IBaseDelegate*>();
	}

	auto& lst = m_eventmap[evtId];

	auto lstIter = find( lst.begin(), lst.end(), p_delegate );
	if ( lstIter == lst.end() )
	{
		lst.push_back( p_delegate );
	}

}

void CBaseEventDispatcher::UnRegister( unsigned int evtId, IBaseDelegate* p_delegate )
{
	auto iter = m_eventmap.find( evtId );
	if ( iter != m_eventmap.end() )
	{
		auto& lst = m_eventmap[evtId];		//��ȡ�����ص��ļ���
		for ( auto lstIter = lst.begin(); lstIter != lst.end(); )
		{
			if ( *lstIter == p_delegate )	//�ҵ�����¼���������������Ըýṹ�����Ƴ�
			{
				lstIter = lst.erase( lstIter );
			}
			else
			{
				lstIter++;
			}
		}
		if ( lst.size() == 0 )	//����Ѿ�û�ж�ĳ���¼������������Ƴ����¼�
		{
			m_eventmap.erase( iter );
		}
	}
	else
	{
		//û������¼�
	}
}


void CBaseEventDispatcher::dispatchEvent( const CBaseEvent& evt )
{
	auto iter = m_eventmap.find( evt.event_id() );
	if ( iter != m_eventmap.end() )
	{
		/*auto& lst = m_eventmap[evt->m_uEventId];
		for ( auto lstIter = lst.begin(); lstIter != lst.end(); ++lstIter )
		{
			(*lstIter)->Fire( evt );
		}*/
		for ( auto delegateIter : (*iter).second )
		{
			delegateIter->Fire( evt );
		}
	}
	else
	{
		//û����������¼����޷�����
	}
}