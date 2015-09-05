#pragma once
#include "BaseModule.h"
#include "TimeTicker.h"
#include "TimeEvent.h"

class TimeModule :
	public BaseModule
{

	friend class ModuleMgr;

public:
	TimeModule();
	~TimeModule();

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


	void tick();


	static DWORD WINAPI TickThread( void *pParam );

private:
	//static TimeModule* m_pInstance;
	TimeTicker* p_TimeTicker;

private:
	static unsigned int ModuleId;

	HANDLE	hThread;
};

