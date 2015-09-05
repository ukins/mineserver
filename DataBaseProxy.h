#pragma once
#include "IDataBase.h"
//#include "DataBaseModule.h"

class DataBaseModule;
/*
	数据库对象的代理类
*/
class DataBaseProxy :
	public IDataBase
{
public:
	DataBaseProxy();
	~DataBaseProxy();


	virtual bool connect();

	//virtual bool query( std::string Sql );
	virtual std::string select_sql( std::string Sql );

	virtual bool insert_sql( std::string Sql );

	virtual bool update_sql( std::string Sql );

	virtual bool delete_sql( std::string Sql );

	virtual void close();

private:
	//数据库对象实例
	IDataBase* m_pDataBase;

	DataBaseModule* m_pDataBaseModule;
};

