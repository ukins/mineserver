#pragma once
#include "LockableObject.h"
/*
 同步锁实现类，基于临界区对象
*/
class LockCriticalSection :
	public LockableObject
{
public:
	LockCriticalSection();
	virtual ~LockCriticalSection();
	virtual void Lock();
	virtual void Unlock();

private:
	CRITICAL_SECTION m_CritSect;
};


