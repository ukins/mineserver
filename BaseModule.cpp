#include "stdafx.h"
#include "BaseModule.h"

unsigned BaseModule::ModuleId = 0;
BaseModule::BaseModule()
{
	//ModuleId = 0;
}


BaseModule::~BaseModule()
{
}

//void BaseModule::setModuleId( unsigned int id)
//{
//	m_usModuleId = id;
//}
//
//unsigned int BaseModule::getModuleId()
//{
//	return m_usModuleId;
//}

void BaseModule::install( void )
{

}

void BaseModule::uninstall( void )
{

}