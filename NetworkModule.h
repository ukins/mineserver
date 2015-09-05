#pragma once
#include "BaseModule.h"
#include "NetworkMgr.h"
#include "NetworkEvent.h"
#include "TimeModule.h"

class NetworkModule :
	public BaseModule
{
public:
	NetworkModule();
	~NetworkModule();

public:
	static unsigned getStaticModuleId()
	{
		return ModuleId;
	}
	static std::string getModuleName()
	{
		return "NetworkModule";
	}
	virtual void setModuleId( unsigned int id )
	{
		ModuleId = id;
	}
	virtual unsigned int getModuleId()
	{
		return ModuleId;
	}


	virtual void install( void );
	virtual void uninstall( void );

	virtual void dispatchEvent( const CBaseEvent& evt );

	void Send( SOCKET s, std::string buffer, u_short protocolId );

private:
	LockCriticalSection m_Lockable;

	CNetworkMgr* m_pNetworkSrv;

	TimeModule* m_pTimeModule;

	static unsigned int ModuleId;
};

