#pragma once
#include "LockableObject.h"
/*
 ͬ����ʵ���࣬�����ٽ�������
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


