#pragma once
#include "BaseEvent.h"
/*
	Î¯ÍÐ½Ó¿Ú
*/
class IBaseDelegate
{
public:
	virtual void Fire( const CBaseEvent& ) = 0;
};

