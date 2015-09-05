#pragma once
#include "BaseEvent.h"
#include "LockList.h"
#include <string>
#include <fstream>

typedef struct Log_Struct
{
	std::string moduleName;
	std::string time;
	std::string logStr;
}LOG_STRUCT,*PLOG_STRUCT;

class LogMgr
{
	friend class LogModule;
public:
	//static LogMgr* getInstance();
	//static void release();

	~LogMgr();

	void start( void );
	void stop( void );

	void onTimeTickSecondHandler( const CBaseEvent* evt );

	void push_log( std::string& strModuleName, std::string& p_strLog );

private:
	LogMgr();

private:
	//static LogMgr* m_pInstnace;

	bool	isRunning;

	std::ofstream logStream;

	LockList<LOG_STRUCT> m_lockList;

	std::string logFileName = "log.txt";

};

