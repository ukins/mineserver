// MineServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include "ModuleMgr.h"
#include "DataBaseModule.h"
#include "TimeModule.h"
#include "LogModule.h"
#include "ProtocolModule.h"
#include "NetworkModule.h"

#include "LoginModule.h"


int _tmain(int argc, _TCHAR* argv[])
{
	ModuleMgr* p_moduleMgr = ModuleMgr::getInstance();

	//<!-- 核心模块
	p_moduleMgr->registerModule( new TimeModule );
	p_moduleMgr->registerModule( new LogModule );
	p_moduleMgr->registerModule( new NetworkModule );
	//p_moduleMgr->registerModule( new ProtocolModule );
	p_moduleMgr->registerModule( new DataBaseModule );
	//-->

	//<!-- 扩展模块
	p_moduleMgr->registerModule( new LoginModule );
	//-->

	while ( true )
	{
		printf( "Please input order:\n" );
		std::string commend;
		std::cin >> commend;
		if (commend == "quit")
		{
			p_moduleMgr->unregisterAll();
			break;
		}
	}
	std::cout << "Server Quit Successfully!\nByeBye..." << std::endl;

	Sleep( 5000 );

	return 0;
}

