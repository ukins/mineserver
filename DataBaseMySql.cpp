#include "stdafx.h"
#include "DataBaseMySql.h"
#include "ModuleMgr.h"
#include "DataBaseModule.h"

DataBaseMySql::DataBaseMySql()
{
	m_pLogModule = (LogModule*)ModuleMgr::getInstance()->getModuleById( LogModule::getStaticModuleId() );
}


DataBaseMySql::~DataBaseMySql()
{
	m_pLogModule = nullptr;
}

bool DataBaseMySql::init_database()
{
	if ( mysql_init( &myConn ) == NULL )
	{
		std::string msg = "mysql_init() failed";
		m_pLogModule->push_log( DataBaseModule::getModuleName(), msg );
		return false;
	}

	return true;
}

bool DataBaseMySql::connect()
{
	if ( init_database() == false )
	{
		return false;
	}
	if ( mysql_real_connect( &myConn, host.c_str(), user.c_str(), pswd.c_str(), db.c_str(), 0, NULL, 0 ) == NULL )
	{
		std::string msg = "mysql_real_connect() failed";
		m_pLogModule->push_log( DataBaseModule::getModuleName(), msg );
		return false;
	}

	char value = 1;
	mysql_options( &myConn, MYSQL_OPT_RECONNECT, (char *)&value );

	if ( mysql_set_character_set( &myConn, "GBK" ) != 0 )
	{
		std::string msg = "mysql_set_character_set() failed";
		m_pLogModule->push_log( DataBaseModule::getModuleName(), msg );
		return false;
	}

	return true;
}

bool DataBaseMySql::ping()
{
	mysql_ping( &myConn );
	return true;
}

std::string DataBaseMySql::select_sql( std::string Sql )
{
	ping();

	if ( mysql_query( &myConn, Sql.c_str() ) != 0 )
	{
		std::string msg = "select_sql() failed. sql is [" + Sql + "]";
		m_pLogModule->push_log( DataBaseModule::getModuleName(), msg );
		return false;
	}

	result = mysql_store_result( &myConn );

	if ( result == NULL )
	{
		std::string msg = "mysql_store_result() failed.";
		m_pLogModule->push_log( DataBaseModule::getModuleName(), msg );
		return "";
	}
	
	size_t fieldsCnt;
	fieldsCnt = mysql_num_fields( result );

	std::string str( "" );
	while ( sql_row = mysql_fetch_row( result ) )
	{
		for ( size_t i = 0; i < fieldsCnt; ++i )
		{
			str += sql_row[i];
			str += cg;
		}
		str += rg;
	}

	mysql_free_result( result );

	return str;
}

bool DataBaseMySql::insert_sql( std::string Sql )
{
	ping();

	if ( mysql_query( &myConn, Sql.c_str() ) != 0 )
	{
		std::string msg = "insert_sql() failed.";
		m_pLogModule->push_log( DataBaseModule::getModuleName(), msg );
		return false;
	}
	return true;
}

bool DataBaseMySql::update_sql( std::string Sql )
{
	ping();

	if ( mysql_query( &myConn, Sql.c_str() ) != 0 )
	{
		std::string msg = "update_sql() failed.";
		m_pLogModule->push_log( DataBaseModule::getModuleName(), msg );
		return false;
	}
	return true;
}

bool DataBaseMySql::delete_sql( std::string Sql )
{
	ping();

	if ( mysql_query( &myConn, Sql.c_str() ) != 0 )
	{
		std::string msg = "delete_sql() failed.";
		m_pLogModule->push_log( DataBaseModule::getModuleName(), msg );
		return false;
	}
	return true;
}

void DataBaseMySql::close()
{
	mysql_close( &myConn );
}