#pragma once
#include "TimeEvent.h"
#include <string>
#include <chrono>
#include "BaseEventDispatcher.h"

class TimeModule;
/*
	¶¨Ê±Æ÷
*/
class TimeTicker
	//public CBaseEventDispatcher
{
	friend class TimeModule;

public:

	~TimeTicker();

	static TimeTicker* GetInstance();
	static void release();


	void start( void );
	void stop( void );

	void tick( void );

	std::string getCurrentTimeStr();

private:
	TimeTicker();

	bool tick_millisecond( long long diff_time );
	bool tick_second( long long diff_time );
	bool tick_minute( long long diff_time );

private:
	static TimeTicker* p_TimeTicker;

	TimeModule* m_pTimeModule;

	bool	isRunning;

	std::chrono::system_clock::time_point startTime;
	std::chrono::system_clock::time_point endTime;

};

