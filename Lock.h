#pragma once
#include "LockableObject.h"

/*
 ��ͬ��������һ��ͬ�������ķ�װ
*/
class Lock
{
public:
	Lock( LockableObject* pLockable );
	~Lock();

private:
	LockableObject* m_pLockable;
};

