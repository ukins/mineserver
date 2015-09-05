#pragma once
#include "BaseModule.h"
#include "LogMgr.h"

/*
	LogÈÕÖ¾Ä£¿é
*/
class LogModule :
	public BaseModule
{
public:
	LogModule();
	~LogModule();

public:
	static unsigned getStaticModuleId()
	{
		return ModuleId;
	}
	static std::string getModuleName()
	{
		return "TimeModule";
	}
	virtual void setModuleId( unsigned int id )
	{
		ModuleId = id;
	}
	virtual unsigned int getModuleId()
	{
		return ModuleId;
	}

	virtual void install();

	virtual void uninstall();

	static DWORD WINAPI logThread( void* pParam );

	void push_log( std::string& strModuleName, std::string& p_strLog );

private:
	LogMgr* m_pLogMgr;

	static const int THREAD_SLEEP_TIME = 1000*1;

	static unsigned int ModuleId;

	HANDLE hThread;

};

