#pragma once
#include "BaseModule.h"
#include "NetworkModule.h"
#include "LogModule.h"
#include "BaseDelegate.h"
#include "DataBaseProxy.h"

/*
	µÇÂ¼Ä£¿é
*/
class LoginModule :
	public BaseModule
{
public:
	LoginModule();
	~LoginModule();

public:
	static unsigned getStaticModuleId()
	{
		return ModuleId;
	}
	static std::string getModuleName()
	{
		return "LoginModule";
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

	void onRecvPackageHandler( const CBaseEvent& evt );


private:
	static unsigned int ModuleId;

	NetworkModule* m_pNetworkModule;
	LogModule* m_pLogModule;

	IBaseDelegate* m_pDelegate;

	DataBaseProxy* m_pDataBase;
};

