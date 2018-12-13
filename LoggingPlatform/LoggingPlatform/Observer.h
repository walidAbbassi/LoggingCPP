#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H

class Logging;
class Observer  // Logging Platform
{
public:
	Observer();
	virtual void update(Logging * pSubject) = 0;
	virtual ~Observer() {}
};

#endif // !OBSERVER_H