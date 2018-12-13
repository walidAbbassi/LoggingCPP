#pragma once
#ifndef CONSOLELOGGINGPLATFORM_H
#define CONSOLELOGGINGPLATFORM_H

#include "Logger.h"
#include <iostream>

class ConsoleLoggingPlatform : public Observer
{
public:
	ConsoleLoggingPlatform();
	void update(Logging * pSubject);
	~ConsoleLoggingPlatform();
};

#endif // !CONSOLELOGGINGPLATFORM_H