#pragma once
#include "LockList.h"
#include "BaseDelegate.h"
#include "TimeTicker.h"

/*
	接受底层向上抛的数据包 (弃用)
*/
class Receive
{
	using SYNC_LIST = LockList < IO_COMPLETE_DATA >;
public:
	virtual ~Receive();

	static Receive* GetInstance( void );
	static void release( void );

	void onEnterFrameHandler( const CBaseEvent& evt );

	//SYNC_DATA *pop_front();

	void push_back( const IO_COMPLETE_DATA* p_SyncData );

private:
	Receive();
	//Receive( const Receive* other );
	//Receive& operator=(Receive& other);

	static Receive* m_pReceive;

	IBaseDelegate* p_delegate;

	TimeTicker* p_TimeTicker;

	SYNC_LIST		m_syncList;

};

