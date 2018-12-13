#pragma once
#ifndef FILELOGGINGPLATFORM_H
#define FILELOGGINGPLATFORM_H

#include "Logger.h"
#include <iostream>

class FileLoggingPlatform : public Observer
{
private:
	std::string fileName;
public:
	FileLoggingPlatform();
	FileLoggingPlatform(std::string name);
	void update(Logging * pSubject);
	~FileLoggingPlatform();
};

#endif // !FILELOGGINGPLATFORM_H