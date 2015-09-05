#include "stdafx.h"
#include "TimeTicker.h"
#include <windows.h>
#include <ctime>
#include "TimeModule.h"
#include "ModuleMgr.h"

TimeTicker* TimeTicker::p_TimeTicker = nullptr;

TimeTicker::TimeTicker()
{
	//m_pTimeModule = (TimeModule*)ModuleMgr::getInstance()->getModuleById( TimeModule::getStaticModuleId() );
}


TimeTicker::~TimeTicker()
{
}

TimeTicker* TimeTicker::GetInstance()
{
	if ( p_TimeTicker == nullptr )
	{
		p_TimeTicker = new TimeTicker();
	}
	return p_TimeTicker;
}

void TimeTicker::release()
{
	if ( p_TimeTicker != nullptr )
	{
		delete p_TimeTicker;
	}
}


void TimeTicker::start( void )
{
	isRunning = true;

	m_pTimeModule = (TimeModule*)ModuleMgr::getInstance()->getModuleById( TimeModule::getStaticModuleId() );

	startTime = std::chrono::system_clock::now();


}

void TimeTicker::stop( void )
{
	isRunning = false;
}

void TimeTicker::tick( void )
{

	if ( isRunning == false )
	{
		return;
	}

	endTime = std::chrono::system_clock::now();
	auto elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>
		(endTime - startTime).count();
	//if ( tick_millisecond( elapsed_seconds ) == true )
	//{
		if ( tick_second( elapsed_seconds ) == true )
		{
			if ( tick_minute( elapsed_seconds ) == true )
			{
			}
		}
	//}

}

bool TimeTicker::tick_millisecond( long long diff_time )
{
	//static unsigned long tick_millisecond_cnt = 0;
	//if ( diff_time > tick_millisecond_cnt * 20 )
	//{
	//	tick_millisecond_cnt++;
	//	if ( tick_millisecond_cnt == 0 )
	//	{
	//		startTime = std::chrono::system_clock::now();
	//	}
	//	CTimeEvent time_evt( CTimeEvent::MILLISECOND_20 );
	//	//TimeModule::getInstance()->dispatchEvent( time_evt );
	//	m_pTimeModule->dispatchEvent( time_evt );

	//	return true;
	//}
	return false;
}

bool TimeTicker::tick_second( long long diff_time )
{
	static unsigned long tick_second_cnt = 0;
	if ( diff_time > tick_second_cnt * 1000 )
	{
		tick_second_cnt++;
		if ( tick_second_cnt == 0 )
		{
			startTime = std::chrono::system_clock::now();
		}
		CTimeEvent time_evt( CTimeEvent::SECOND );
		m_pTimeModule->dispatchEvent( time_evt );

		return true;
	}
	return false;
}

bool TimeTicker::tick_minute( long long diff_time )
{
	static unsigned long tick_minute_cnt = 0;
	if ( diff_time > tick_minute_cnt * 60 * 1000 )
	{
		tick_minute_cnt++;
		CTimeEvent time_evt( CTimeEvent::MUNITE );
		m_pTimeModule->dispatchEvent( time_evt );

		return true;
	}
	return false;
}

std::string TimeTicker::getCurrentTimeStr()
{
	char buffer[64];
	auto currentTime = std::chrono::system_clock::now();
	auto end_time = std::chrono::system_clock::to_time_t( currentTime );
	ctime_s( buffer, 64, &end_time );
	size_t len = strlen( buffer );
	buffer[len - 1] = '\0';
	//std::string str = buffer;
	return buffer;
}
