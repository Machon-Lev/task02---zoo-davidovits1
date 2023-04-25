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
	std::cout << "direction: " << direction << std::endl;
}


Location Animal::getLocation() const
{
	return location;
}

std::string Animal::getName() const
{
	return name;
}

Direction Animal::getDirection() const
{
	return direction;
}

void Animal::stop()
{
	mooving = false;
}

void Animal::move()
{
	mooving = true;
}

std::ostream& operator<<(std::ostream& os, Direction dir)
{

	switch (dir) {
	case Direction::Up: return os << "Up";
	case Direction::Down: return os << "Down";
	case Direction::Left: return os << "Left";
	case Direction::Right: return os << "Right";
	case Direction::UpLeft: return os << "UpLeft";
	case Direction::UpRight: return os << "UpRight";
	case Direction::DownLeft: return os << "DownLeft";
	case Direction::DownRight: return os << "DownRight";
	default: return os;


	}
}
