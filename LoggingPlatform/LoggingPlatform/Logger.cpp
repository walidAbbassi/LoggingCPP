#include "stdafx.h"
#include "Logger.h"


Logger::Logger()
{
	messageStatusMap[ERROR] = true;
	messageStatusMap[WARNING] = true;
	messageStatusMap[INFO] = true;
	messageStatusMap[DEBUG] = true;
}

void Logger::writeLog(MessageType type, const std::string &location, const std::string &message)
{
	if (messageStatusMap[type])
	{
		setData(location + message,type);
		notify(type);
	}
}

void Logger::enableLoggingOfMessage(MessageType type)
{
	messageStatusMap[type] = true;
}

void Logger::disableLoggingOfMessage(MessageType type)
{
	messageStatusMap[type] = false;
}


Logger::~Logger()
{
}
