#pragma once
#include "IBaseDelegate.h"
/*
	委托,基类
*/
template < typename O, typename T >
class CBaseDelegate : public IBaseDelegate
{
	using CallBack_Func = void(T::*)(const CBaseEvent&);
public:
	CBaseDelegate( O* pObj = nullptr, CallBack_Func pFunc = nullptr )
		:m_pFunc( pFunc ), m_pObj( pObj )
	{

	}

	~CBaseDelegate()
	{
		delete m_pFunc;
		m_pFunc = nullptr;

		delete m_pObj;
		m_pObj = nullptr;
	}
	
	//触发事件
	virtual void Fire( const CBaseEvent& evt)
	{
		if ( m_pFunc != nullptr && m_pObj != nullptr )
		{
			(m_pObj->*m_pFunc)(evt);
		}
	}

private:
	//回调函数指针
	CallBack_Func m_pFunc;
	//回调函数所属的对象
	O* m_pObj;
};

//生成委托对象
template<typename O,typename T>
CBaseDelegate<O, T>* MakeDelegate( O* pObj, void(T::*pFunc)(const CBaseEvent&) )
{
	return new CBaseDelegate<O, T>( pObj, pFunc );
}
