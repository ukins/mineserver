#pragma once
#include "BaseModule.h"
#include <map>

class ModuleMgr
{
public:
	ModuleMgr();
	~ModuleMgr();

public:
	static ModuleMgr* getInstance();
	static void release();

	void registerModule( BaseModule* p_baseModule );
	void unregisterModule( BaseModule* p_baseModle );
	void unregisterAll();

	BaseModule* getModuleById( unsigned id );

private:
	inline unsigned getNewModuleId()
	{
		return (unsigned)(m_modulesMap.size()+1);
	}

private:
	static ModuleMgr* p_moduleMgr;

	std::map<unsigned int, BaseModule*> m_modulesMap;
};

