#include "stdafx.h"
#include "LogModule.h"

unsigned LogModule::ModuleId = 0;
LogModule::LogModule()
{
	m_pLogMgr = new LogMgr;
}


LogModule::~LogModule()
{
	delete m_pLogMgr;
	m_pLogMgr = nullptr;
}

void LogModule::install()
{
	m_pLogMgr->start();

	DWORD dwThreadId;
	hThread = CreateThread( NULL, 0, logThread, this, 0, &dwThreadId );
	if ( hThread == NULL )
	{
		m_pLogMgr->stop();
		throw "Error: Create TickThread failed";
	}
	/*else
	{
		CloseHandle( hThread );
	}*/

	printf( "LogModule install succeed!\n" );
}

void LogModule::uninstall()
{
	m_pLogMgr->stop();

	::WaitForSingleObject( hThread, INFINITE );
	CloseHandle( hThread );
	hThread = nullptr;

	printf( "LogModule uninstall succeed!\n" );
}

DWORD WINAPI LogModule::logThread( void* pParam )
{
	LogModule* p_LogModule = (LogModule*)pParam;
	LogMgr* m_plogmgr = p_LogModule->m_pLogMgr;
	while ( m_plogmgr->isRunning == true )
	{
		m_plogmgr->logStream.open( m_plogmgr->logFileName, std::ofstream::app | std::ofstream::out );

		while ( !m_plogmgr->m_lockList.IsEmpty() )
		{
			PLOG_STRUCT pLog_struct = m_plogmgr->m_lockList.pop();

			m_plogmgr->logStream << "[MODULE]: " << pLog_struct->moduleName << ";\t"
				<< "[TIME]: " << pLog_struct->time << ";\t"
				<< "[DESC]: " << pLog_struct->logStr << ";\n\n";

			delete pLog_struct;
			pLog_struct = nullptr;

		}

		m_plogmgr->logStream.close();

		Sleep( THREAD_SLEEP_TIME );
	}

	printf( "LogThread return\n" );

	return 0;
}

void LogModule::push_log( std::string& strModuleName, std::string& p_strLog )
{
	m_pLogMgr->push_log( strModuleName, p_strLog );
}