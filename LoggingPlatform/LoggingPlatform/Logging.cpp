#include "stdafx.h"
#include "Logging.h"

void Logging::setData(const std::string &value, MessageType type)
{
	 data = "[ " + getCurrentTime() +" ] "+ "[ " + getMessageLevel(type) + " ] " + value +".\n";
}

void Logging::attach(const int &event, std::shared_ptr<Observer> pObsrvr)
{
	registryMap[event].push_back(pObsrvr);
}

void Logging::deattach(std::shared_ptr<Observer> pObsrvr)
{
	for (auto it = registryMap.begin(); it != registryMap.end(); ++it)
	{
		auto itV = std::find(it->second.begin(), it->second.end(), pObsrvr);
		if (itV != it->second.end())
		{
			it->second.erase(itV);
			continue;
		}
	}
}

void Logging::notify(const int &event)
{
	auto it = registryMap.find(event);
	if (it != registryMap.end())
	{
		for (auto itV = it->second.begin(); itV != it->second.end(); itV++)
		{
			(*itV)->update(this);
		}
	}
}

std::string Logging::getCurrentTime() const
{
	std::stringstream strCurrentTime;
	const auto currentTime = std::chrono::system_clock::now();
	const auto currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
	const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime.time_since_epoch()) % 1000;
	strCurrentTime << std::put_time(std::localtime(&currentTime_t), "%a %b %d %Y %T")
		<< '.' << std::setfill('0') << std::setw(3) << nowMs.count();
	return strCurrentTime.str();
}

const std::string Logging::getMessageLevel(const int &event)
{
	return MessageLevelMapType[event];
}

Logging::Logging()
{
}

std::string Logging::getData() const
{
	return data; 
}


Logging::~Logging()
{
}
