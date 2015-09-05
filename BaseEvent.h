#pragma once
/*
	事件基类 事件类型ID [1~1000);
*/
class CBaseEvent
{
public:
	CBaseEvent( unsigned int id ) :m_uEventId( id ){};


	~CBaseEvent()
	{
		if ( nullptr == m_pArgs )
		{
			delete m_pArgs;
			m_pArgs = nullptr;
		}
	}

	unsigned int event_id()
	{
		return m_uEventId;
	}
	unsigned int event_id() const
	{
		return m_uEventId;
	}

public:

	//static const unsigned COMPELTE = 1;

	//相关参数
	void* m_pArgs = nullptr;

protected:
	//事件类型
	const unsigned int m_uEventId = 0;
};

