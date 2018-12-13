#include "stdafx.h"
#include "ConsoleLoggingPlatform.h"


ConsoleLoggingPlatform::ConsoleLoggingPlatform()
{
}

void ConsoleLoggingPlatform::update(Logging * pSubject)
{
	std::cout << pSubject->getData().c_str() << std::endl;
}


ConsoleLoggingPlatform::~ConsoleLoggingPlatform()
{
}
