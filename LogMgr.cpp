#include "stdafx.h"
#include "LogMgr.h"
#include "TimeTicker.h"

//LogMgr* LogMgr::m_pInstnace = nullptr;
LogMgr::LogMgr()
{
}


LogMgr::~LogMgr()
{
}

//LogMgr* LogMgr::getInstance()
//{
//	if ( m_pInstnace == nullptr )
//	{
//		m_pInstnace = new LogMgr;
//	}
//	return m_pInstnace;
//}
//
//void LogMgr::release()
//{
//	if ( m_pInstnace != nullptr )
//	{
//		delete m_pInstnace;
//		m_pInstnace = nullptr;
//	}
//}

void LogMgr::start( void )
{
	isRunning = true;

}

void LogMgr::stop( void )
{
	isRunning = false;
}

void LogMgr::push_log( std::string& strModuleName,std::string& strLog )
{
	PLOG_STRUCT pLogStruct = new LOG_STRUCT;

	pLogStruct->moduleName = strModuleName;
	pLogStruct->time = TimeTicker::GetInstance()->getCurrentTimeStr();
	pLogStruct->logStr = strLog;

	m_lockList.push( pLogStruct );
}