#pragma once
#include <string>
/*
	���ݿ�ӿ���
*/
class IDataBase
{
public:
	//virtual bool init_database() = 0;

	//�������ݿ�
	virtual bool connect() = 0;

	//virtual bool ping() = 0;

	//ִ�����ݿ���������� select, insert, update, delete
	//virtual bool query( std::string Sql ) = 0;

	virtual std::string select_sql( std::string Sql ) = 0;

	virtual bool insert_sql( std::string Sql ) = 0;

	virtual bool update_sql( std::string Sql ) = 0;

	virtual bool delete_sql( std::string Sql ) = 0;

	//�ر����ݿ�����
	virtual void close() = 0;
};

