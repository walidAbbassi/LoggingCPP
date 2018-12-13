#include "stdafx.h"
#include "FileLoggingPlatform.h"


FileLoggingPlatform::FileLoggingPlatform()
{
}

FileLoggingPlatform::FileLoggingPlatform(std::string name) : fileName(name) 
{
	
}


void FileLoggingPlatform::update(Logging * pSubject)
{
	std::string data = pSubject->getData();
	std::cout << "Written in file \n" << data.c_str() << std::endl;
	// Add data to file
}

FileLoggingPlatform::~FileLoggingPlatform()
{
}
