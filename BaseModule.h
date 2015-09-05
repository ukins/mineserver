#pragma once
#include "BaseEventDispatcher.h"
/*
	模块基类 继承自CBaseEventDispatcher
*/
class BaseModule
	: public CBaseEventDispatcher
{
public:
	BaseModule();
	~BaseModule();

public:
	// <!-- 以下方法必须在子类中重写
	//getStaticModuleId(), setModuleId(), getModuleId(),
	//getModuleName(), install(), uninstall();

	//通过静态方式去获取模块ID
	static unsigned getStaticModuleId()
	{
		return ModuleId;
	}

	//通过非静态方式去设置模块Id
	virtual void setModuleId( unsigned int id ) = 0;
	/*{
		ModuleId = id;
	}*/


	//通过非静态方式获取模块Id
	virtual unsigned int getModuleId() = 0;
	/*{
		return ModuleId;
	}*/

	//获取模块名称
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

