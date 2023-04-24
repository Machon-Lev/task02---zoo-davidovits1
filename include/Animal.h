#pragma once
#include <string>
#include "Location.h"

class Animal {
protected:
	bool mooving = true;
	std::string name;
	Location location;
	

public:
	Animal(): location() {};
	//Animal(const std::string& n, const Location& l);
	Animal(const std::string& n, const Location& l) : name(n), location(l) {}
	virtual void printDetails() const;
	virtual char getInitial() const = 0;
	Location getLocation() const;
	virtual std::string getName() const;
	virtual void step() = 0;
	void stop();
	virtual void move();
	virtual void turnVertically() = 0;
	virtual void turnHorizontally() = 0;
};