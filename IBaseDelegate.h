#pragma once
#include "BaseEvent.h"
/*
	ί�нӿ�
*/
class IBaseDelegate
{
public:
	virtual void Fire( const CBaseEvent& ) = 0;
};

