#pragma once
#include "BaseModule.h"
#include "BaseDelegate.h"
#include "NetworkModule.h"
#include "LogModule.h"
/*
	逻辑层收发协议模块
*/
class ProtocolModule :
	public BaseModule
{
public:
	ProtocolModule();
	~ProtocolModule();

public:

	static unsigned getStaticModuleId()
	{
		return ModuleId;
	}
	static std::string getModuleName()
	{
		return "ProtocolModule";
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

	IBaseDelegate* m_pDelegate;
	NetworkModule* m_pNetworkModule;
	LogModule* m_pLogModule;


	static unsigned int ModuleId;

};

