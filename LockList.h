#pragma once
#include <list>
#include "LockCriticalSection.h"
#include "Lock.h"

/*
* 具有同步机制的容器，基于List实现
*/
template<typename T>
class LockList
{
	using LIST = std::list < T* > ;
	using SIZETYPE = typename std::list < T* >::size_type;
	//typedef typename std::list < T* >::size_type size_type;
public:
	LockList( void );

	~LockList( void );

	//返回列表首部的元素，同时在列表中将元素删除，
	//若当前列表中没有元素，则返回nullptr;
	T* pop();

	//在列表尾部插入元素
	bool push( T* p_t );

	//bool push( const T* p_t );

	//获取列表的元素个数
	typename SIZETYPE GetLength();

	//判断列表当前是否为空
	bool IsEmpty();

private:
	LockCriticalSection m_Lockable;
	LIST				m_pList;
};



template<typename T>
LockList<T>::LockList()
{
	m_pList.clear();
}

template<typename T>
LockList<T>::~LockList()
{
}

template<typename T>
T* LockList<T>::pop()
{
	Lock localLock( &m_Lockable );

	if ( IsEmpty() )
	{
		return nullptr;
	}
	auto iter = m_pList.begin();
	T* p_t = *iter;
	m_pList.erase( iter );

	return p_t;
}

template<typename T>
bool LockList<T>::push( T* p_t )
{
	Lock localLock( &m_Lockable );
	if ( p_t == NULL )
	{
		return false;
	}
	m_pList.push_back( p_t );
	return true;
}

//template<typename T>
//bool LockList<T>::push( const T* p_t )
//{
//	//Lock localLock( &m_Lockable );
//	//if ( p_t == NULL )
//	//{
//	//	return false;
//	//}
//	//m_pList.push_back( p_t );
//	return true;
//}

template < typename T >
typename LockList<T>::SIZETYPE LockList<T>::GetLength()
{
	Lock localLock( &m_Lockable );

	return m_pList.size();
}

template<typename T>
bool LockList<T>::IsEmpty()
{
	return m_pList.empty();
}

