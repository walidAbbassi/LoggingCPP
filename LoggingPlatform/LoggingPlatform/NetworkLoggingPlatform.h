#pragma once
#ifndef NETWORKLOGGINGPLATFORM_H
#define NETWORKLOGGINGPLATFORM_H

#include "Logger.h"
#include <iostream>

class NetworkLoggingPlatform : public Observer
{
public:
	NetworkLoggingPlatform();
	void update(Logging * pSubject);
	~NetworkLoggingPlatform();
};

#endif // !NETWORKLOGGINGPLATFORM_H