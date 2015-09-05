#pragma once
#include <string>
/*
	数据库接口类
*/
class IDataBase
{
public:
	//virtual bool init_database() = 0;

	//连接数据库
	virtual bool connect() = 0;

	//virtual bool ping() = 0;

	//执行数据库操作，包括 select, insert, update, delete
	//virtual bool query( std::string Sql ) = 0;

	virtual std::string select_sql( std::string Sql ) = 0;

	virtual bool insert_sql( std::string Sql ) = 0;

	virtual bool update_sql( std::string Sql ) = 0;

	virtual bool delete_sql( std::string Sql ) = 0;

	//关闭数据库链接
	virtual void close() = 0;
};

