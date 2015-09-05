#pragma once
#include "BaseModule.h"
#include "DataBaseProxy.h"
/*
	Êý¾Ý¿âÄ£¿é
*/
class DataBaseModule :
	public BaseModule
{
public:
	DataBaseModule();
	~DataBaseModule();

public:
	static unsigned getStaticModuleId()
	{
		return ModuleId;
	}
	static std::string getModuleName()
	{
		return "DataBaseModule";
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

	DataBaseProxy* getDataBaseProxy()
	{
		return m_pDataBaseProxy;
	}

private:
	static unsigned int ModuleId;

	DataBaseProxy* m_pDataBaseProxy;
};

