#include "stdafx.h"
#include "ModuleMgr.h"

ModuleMgr* ModuleMgr::p_moduleMgr = nullptr;
ModuleMgr::ModuleMgr()
{
	m_modulesMap.clear();
}


ModuleMgr::~ModuleMgr()
{

}

ModuleMgr* ModuleMgr::getInstance()
{
	if ( p_moduleMgr == nullptr )
	{
		p_moduleMgr = new ModuleMgr;
	}
	return p_moduleMgr;
}

void ModuleMgr::release()
{
	if ( p_moduleMgr != nullptr )
	{
		delete p_moduleMgr;
		p_moduleMgr = nullptr;
	}
}

void ModuleMgr::registerModule( BaseModule* p_baseModule )
{
	p_baseModule->setModuleId( getNewModuleId() );
	m_modulesMap.insert( { p_baseModule->getModuleId(), p_baseModule } );
	p_baseModule->install();
}


void ModuleMgr::unregisterModule( BaseModule* p_baseModle )
{
	auto iter = m_modulesMap.find( p_baseModle->getModuleId() );
	if ( iter == m_modulesMap.end() )
	{
		return;
	} 
	else
	{
		p_baseModle->uninstall();
		delete p_baseModle;
		p_baseModle = nullptr;
		m_modulesMap.erase( iter );
	}
}

void ModuleMgr::unregisterAll()
{
	for ( auto iter = m_modulesMap.rbegin(); iter != m_modulesMap.rend(); ++iter )
	{
		BaseModule* p_baseModule = iter->second;
		p_baseModule->uninstall();
		delete p_baseModule;
		p_baseModule = nullptr;
	}
	m_modulesMap.clear();
}

BaseModule* ModuleMgr::getModuleById( unsigned id )
{
	auto iter = m_modulesMap.find( id );
	if ( iter == m_modulesMap.end() )
	{
		printf( "getModuleById failed!\n" );
		return nullptr;
	}
	return (*iter).second;
}