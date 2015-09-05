#pragma once
#include "LockableObject.h"

/*
 对同步锁对象一次同步操作的封装
*/
class Lock
{
public:
	Lock( LockableObject* pLockable );
	~Lock();

private:
	LockableObject* m_pLockable;
};

