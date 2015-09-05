#pragma once
#include "IDataBase.h"
#include <mysql.h>
#include <string>
#include "LogModule.h"
#include "DataBaseModule.h"

//#include <windows.h>

/*
	数据库具体类，MySql
*/
class DataBaseMySql :
	public IDataBase
{
public:
	DataBaseMySql();
	~DataBaseMySql();

	virtual bool connect();

	virtual std::string select_sql( std::string Sql );

	virtual bool insert_sql( std::string Sql );

	virtual bool update_sql( std::string Sql );

	virtual bool delete_sql( std::string Sql );

	virtual void close();

private:
	//初始化
	bool init_database();

	//
	bool ping();

private:
	const std::string user = "root";			//username
	const std::string pswd = "123456";			//password
	const std::string host = "localhost";		//or "127.0.0.1"
	const std::string db = "test";				//database
	const unsigned int port = 3306;				//server port

	MYSQL		myConn;
	MYSQL_RES	*result;
	MYSQL_ROW	sql_row;
	MYSQL_FIELD	*fd;

	const char rg = 0x06;//行分隔字符
	const char cg = 0x05;//字段分隔字符

	LogModule* m_pLogModule;
	DataBaseModule* m_pDataBaseModule;
};

