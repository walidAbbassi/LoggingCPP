#pragma once
#pragma warning(disable : 4996)
#ifndef LOGGING_H
#define LOGGING_H
#include <map>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <map>
#include "Observer.h"
#include "MessageLevel.h"
#include <memory>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT  ("[ " __FUNCTION__ " : " TOSTRING(__LINE__) " ] ")

class Logging
{
private:
	std::map<int, std::string> MessageLevelMapType = {
		{ FATAL, "FATAL" },
		{ ERROR, "ERROR" },
		{ WARNING, "WARNING" },
		{ INFO, "INFO" },
		{ DEBUG, "DEBUG" },
		{ TRACE, "TRACE" }
	};
	std::map<int, std::vector<std::shared_ptr<Observer>> > registryMap;
	std::string data;
public:
	Logging();
	std::string getData() const;
	void setData(const std::string &value, MessageType type);
	void attach(const int &event, std::shared_ptr<Observer> pObsrvr);
	void deattach(std::shared_ptr<Observer> pObsrvr);
	void notify(const int &event);
	std::string getCurrentTime() const;
	const std::string getMessageLevel(const int &event);
	~Logging();
};

#endif // !LOGGING_H
