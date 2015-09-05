#include "stdafx.h"
#include "TimeModule.h"

unsigned TimeModule::ModuleId = 0;
TimeModule::TimeModule()
{

	p_TimeTicker = TimeTicker::GetInstance();

	hThread = nullptr;
}


TimeModule::~TimeModule()
{
	delete p_TimeTicker;
	p_TimeTicker = nullptr;
}

void TimeModule::install( void )
{
	p_TimeTicker->start();

	//创建接受客户端请求线程
	/*DWORD dwThreadID;
	hThread = CreateThread( NULL, 0, TickThread, this, 0, &dwThreadID );
	if ( NULL == hThread )
	{
		p_TimeTicker->stop();
		throw "Error: Create TickThread failed";
	}*/

	printf( "TimeModule install succeed!\n" );

}

void TimeModule::uninstall( void )
{
	p_TimeTicker->stop();

	//::WaitForSingleObject( hThread, INFINITE );
	//CloseHandle( hThread );
	//hThread = nullptr;

	printf( "TimeModule uninstall succeed!\n" );
}

DWORD WINAPI TimeModule::TickThread( void *pParam )
{
	TimeModule* p_TimeModule = (TimeModule*)pParam;
	TimeTicker* p_TimeTicker = p_TimeModule->p_TimeTicker;
	while ( p_TimeTicker->isRunning == true )
	{
		p_TimeTicker->tick();
		Sleep( 500 );
	}

	printf( "TickThread return\n" );

	return 0;
}

void TimeModule::tick()
{
	p_TimeTicker->tick();
}