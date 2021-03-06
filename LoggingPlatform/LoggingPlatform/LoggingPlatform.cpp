// LoggingPlatform.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Logger.h"
#include "ConsoleLoggingPlatform.h"
#include "FileLoggingPlatform.h"
#include "NetworkLoggingPlatform.h"

int main()
{
	std::shared_ptr<Logger> pLogger = std::make_shared<Logger>();
	std::shared_ptr<ConsoleLoggingPlatform> pConsolePlatform = std::make_shared<ConsoleLoggingPlatform>();
	std::shared_ptr<FileLoggingPlatform> pFilePlatform = std::make_shared<FileLoggingPlatform>("temp");
	std::shared_ptr<NetworkLoggingPlatform> pNetworkPlatform = std::make_shared<NetworkLoggingPlatform>();

	pLogger->attach(ERROR, pConsolePlatform);
	pLogger->attach(WARNING, pConsolePlatform);
	pLogger->attach(INFO, pConsolePlatform);
	pLogger->attach(ERROR, pFilePlatform);
	pLogger->attach(INFO, pNetworkPlatform);

	pLogger->writeLog(ERROR, AT, "This is error");
	pLogger->writeLog(WARNING, AT, "This is warning");
	pLogger->writeLog(INFO, AT, "This is general message");

	pLogger->disableLoggingOfMessage(ERROR);
	pLogger->deattach(pConsolePlatform);

	pLogger->writeLog(ERROR, AT, "This is error 2");
	pLogger->writeLog(INFO, AT, "This is general message 2");

	system("pause");
    return 0;
}

