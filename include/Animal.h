#pragma once
#include <string>
#include "Location.h"
#include "Direction.h"

class Animal {
protected:
	bool isMoving = true;
	std::string name;
	Location location;
	Direction direction;
	

public:
	static Location random();
	Animal(): location() {};
	Animal(const std::string& n, const Location& l) : name(n), location(l) {}
	Animal(const std::string& n);
	bool getIsMoveing();
	virtual void printDetails() const;
	virtual char getInitial() const = 0;
	Location getLocation() const;
	virtual std::string getName() const;
	virtual Direction getDirection() const;
	virtual void step() = 0;
	void stop();
	virtual void move();
	virtual void turnVertically() = 0;
	virtual void turnHorizontally() = 0;

};
std::ostream& operator<<(std::ostream& os, Direction dir);