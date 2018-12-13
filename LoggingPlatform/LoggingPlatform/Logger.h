#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include "Logging.h"
#include <string>
#include <map>

class Logger : public Logging
{
private:
	std::map<MessageType, int> messageStatusMap;
public:
	Logger();
	void writeLog(MessageType type, const std::string &location, const std::string &message);
	void enableLoggingOfMessage(MessageType type);
	void disableLoggingOfMessage(MessageType type);
	~Logger();
};

#endif // !LOGGER