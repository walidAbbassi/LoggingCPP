#include "stdafx.h"
#include "NetworkLoggingPlatform.h"


NetworkLoggingPlatform::NetworkLoggingPlatform()
{
}

void NetworkLoggingPlatform::update(Logging * pSubject)
{
	std::string data = pSubject->getData();
	std::cout << "Sent on network \n" << data.c_str() << std::endl;
	// Send data in network
}


NetworkLoggingPlatform::~NetworkLoggingPlatform()
{
}
