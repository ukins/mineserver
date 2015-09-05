#include "stdafx.h"
#include "DataBaseProxy.h"
#include "DataBaseMySql.h"
#include "ModuleMgr.h"
#include "DataBaseModule.h"

DataBaseProxy::DataBaseProxy()
{
	m_pDataBase = new DataBaseMySql;

	m_pDataBaseModule = (DataBaseModule*)ModuleMgr::getInstance()->getModuleById( DataBaseModule::getStaticModuleId() );
}


DataBaseProxy::~DataBaseProxy()
{
	delete m_pDataBase;
	m_pDataBase = nullptr;

	m_pDataBaseModule = nullptr;
}

bool DataBaseProxy::connect()
{
	return m_pDataBase->connect();
}

std::string DataBaseProxy::select_sql( std::string Sql )
{
	return m_pDataBase->select_sql( Sql );
}

bool DataBaseProxy::insert_sql( std::string Sql )
{
	return m_pDataBase->insert_sql( Sql );
}

bool DataBaseProxy::update_sql( std::string Sql )
{
	return m_pDataBase->update_sql( Sql );
}

bool DataBaseProxy::delete_sql( std::string Sql )
{
	return m_pDataBase->delete_sql( Sql );
}

void DataBaseProxy::close()
{
	m_pDataBase->close();
}