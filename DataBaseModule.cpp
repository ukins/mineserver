#include "stdafx.h"
#include "DataBaseModule.h"

unsigned DataBaseModule::ModuleId = 0;
DataBaseModule::DataBaseModule()
{
}


DataBaseModule::~DataBaseModule()
{
}

void DataBaseModule::install( void )
{
	m_pDataBaseProxy = new DataBaseProxy;

	if ( m_pDataBaseProxy->connect() == true )
	{
		printf( "DataBase Connect Succeed\n" );
	}
	else
	{
		printf( "DataBase Connect Failed\n" );
	}

	printf( "DataBaseModule install succeed!\n" );

}

void DataBaseModule::uninstall( void )
{
	m_pDataBaseProxy->close();

	delete m_pDataBaseProxy;
	m_pDataBaseProxy = nullptr;

	printf( "DataBaseModule uninstall succeed!\n" );
}