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
	if ( iter == m_eventmap.end() )		//没有找到相关事件的侦听集合
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
		auto& lst = m_eventmap[evtId];		//获取侦听回调的集合
		for ( auto lstIter = lst.begin(); lstIter != lst.end(); )
		{
			if ( *lstIter == p_delegate )	//找到相关事件的侦听函数，则对该结构进行移除
			{
				lstIter = lst.erase( lstIter );
			}
			else
			{
				lstIter++;
			}
		}
		if ( lst.size() == 0 )	//如果已经没有对某个事件的侦听，则移除该事件
		{
			m_eventmap.erase( iter );
		}
	}
	else
	{
		//没有相关事件
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
		//没有侦听相关事件，无法触发
	}
}