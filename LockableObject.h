#pragma once
/*
 ͬ�������󣬳������
*/
class LockableObject
{
public:
	LockableObject(){};
	virtual ~LockableObject(){};

	virtual void Lock() = 0;
	virtual void Unlock() = 0;
};

