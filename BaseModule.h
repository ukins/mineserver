#pragma once
#include "BaseEventDispatcher.h"
/*
	ģ����� �̳���CBaseEventDispatcher
*/
class BaseModule
	: public CBaseEventDispatcher
{
public:
	BaseModule();
	~BaseModule();

public:
	// <!-- ���·�����������������д
	//getStaticModuleId(), setModuleId(), getModuleId(),
	//getModuleName(), install(), uninstall();

	//ͨ����̬��ʽȥ��ȡģ��ID
	static unsigned getStaticModuleId()
	{
		return ModuleId;
	}

	//ͨ���Ǿ�̬��ʽȥ����ģ��Id
	virtual void setModuleId( unsigned int id ) = 0;
	/*{
		ModuleId = id;
	}*/


	//ͨ���Ǿ�̬��ʽ��ȡģ��Id
	virtual unsigned int getModuleId() = 0;
	/*{
		return ModuleId;
	}*/

	//��ȡģ������
	//virtual std::string getModuleName() = 0;
	//{
	//	return "BaseModule";
	//}

	virtual void install( void );

	virtual void uninstall( void );

	// -->

private:
	static unsigned int ModuleId;

};

