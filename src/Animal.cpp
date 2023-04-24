#include "Animal.h"

//Animal::Animal(const std::string& n, const Location& l)
//{
//	name = n;
//	location = l;
//}

void Animal::printDetails() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Location: " << location << std::endl;
}

Location Animal::getLocation() const
{
	return location;
}

std::string Animal::getName() const
{
	return name;
}

void Animal::stop()
{
	mooving = false;
}

void Animal::move()
{
	mooving = true;
}
