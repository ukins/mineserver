#include "stdafx.h"
#include "Lock.h"


Lock::Lock( LockableObject* pLockable )
{
	m_pLockable = pLockable;
	m_pLockable->Lock();
}


Lock::~Lock()
{
	m_pLockable->Unlock();
}
