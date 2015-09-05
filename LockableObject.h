#pragma once
/*
 同步锁对象，抽象基类
*/
class LockableObject
{
public:
	LockableObject(){};
	virtual ~LockableObject(){};

	virtual void Lock() = 0;
	virtual void Unlock() = 0;
};

