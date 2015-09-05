#include "stdafx.h"
#include "LockCriticalSection.h"

LockCriticalSection::LockCriticalSection()
{
	InitializeCriticalSection( &m_CritSect );
}

LockCriticalSection::~LockCriticalSection()
{
	DeleteCriticalSection( &m_CritSect );
}

void LockCriticalSection::Lock()
{
	EnterCriticalSection( &m_CritSect );
}

void LockCriticalSection::Unlock()
{
	LeaveCriticalSection( &m_CritSect );
}
