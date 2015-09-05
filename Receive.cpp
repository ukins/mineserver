#include "stdafx.h"
#include "Receive.h"
#include "TimeEvent.h"

#include <iostream>

#include "people.pb.h"
//#include "include/proto/echo_str.pb.h"

Receive *Receive::m_pReceive = nullptr;
Receive::Receive()
{
	p_delegate = MakeDelegate( this, &Receive::onEnterFrameHandler );

	/*p_TimeTicker = TimeTicker::GetInstance();
	p_TimeTicker->Register( CTimeEvent::MILLISECOND_20, p_delegate );*/
	GOOGLE_PROTOBUF_VERIFY_VERSION;
}


Receive::~Receive()
{
	//p_TimeTicker->UnRegister( CTimeEvent::MILLISECOND_20, p_delegate );
	//p_TimeTicker = nullptr;
	//delete p_delegate;
	//p_delegate = nullptr;
	google::protobuf::ShutdownProtobufLibrary();
}

Receive* Receive::GetInstance()
{
	if ( nullptr == m_pReceive )
	{
		m_pReceive = new Receive();
	}

	return m_pReceive;
}

void Receive::release()
{
	if ( nullptr != m_pReceive )
	{
		delete m_pReceive;
		m_pReceive = nullptr;
	}
}

void Receive::push_back( const IO_COMPLETE_DATA* p_SyncData )
{
	//m_syncList.push( p_SyncData );

	//TimeTicker *pTimeTicker = TimeTicker::GetInstance();
	//pTimeTicker->tick();
}

void Receive::onEnterFrameHandler( const CBaseEvent& evt )
{
	while (!m_syncList.IsEmpty())
	{
		IO_COMPLETE_DATA* p_io_complete_data = m_syncList.pop();
		CPFS::People p;
		p.ParseFromString( p_io_complete_data->buffer );
		p.name();
		p.id();
		p.email();
		/*	TEST::Echo_Str p;
			p.ParseFromString( p_io_complete_data->buffer );*/
		
		std::cout << p_io_complete_data->usMsgId << "\t\t" << p_io_complete_data->buffer << std::endl;
		std::cout << p.name() << std::endl;
	}

}