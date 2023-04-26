#include "Lion.h"

Lion::Lion() : Animal()
{
	int directionInt = rand() % 2 + 2;
	direction = static_cast<Direction>(directionInt);
}

Lion::Lion(const std::string& n, const Location& l) : Animal(n, l)
{
	int directionInt = rand() % 2 + 2;
	direction = static_cast<Direction>(directionInt);
}

Lion::Lion(const std::string& n) : Animal(n)
{
	int directionInt = rand() % 2 + 2;
	direction = static_cast<Direction>(directionInt);
}

std::string Lion::getType() const
{
	return "Lion";
}

void Lion::printDetails() const
{
	std::cout << "Kind: Lion" << std::endl;
	Animal::printDetails();
}

char Lion::getInitial() const
{
	return 'L';
}

void Lion::step()
{
	if (isMoving)
	{
		switch (direction)
		{
		case Direction::Left:
			if (location.col >= 2)
			{
				Location l(0, -LIONMOVE);
				location += l;
			}
			else
			{
				direction = Direction::Right;
				if (location.col < 1)
				{
					Location l(0, LIONMOVE);
					location += l;
				}
			}
			break;
		case Direction::Right:
			if (location.col <= 37)
			{
				Location l(0, LIONMOVE);
				location += l;
			}
			else
			{
				direction = Direction::Left;
				if (location.col > 38)
				{
					Location l(0, -LIONMOVE);
					location += l;
				}
			}
			break;
		default:
			break;
		}
	}
}

void Lion::turnVertically()
{
}

void Lion::turnHorizontally()
{
	switch (direction)
	{
	case Direction::Left:
		direction = Direction::Right;
		break;
	case Direction::Right:
		direction = Direction::Left;
		break;
	}
}

void Lion::move()
{
	Animal::move();
	int directionInt = rand() % 2 + 2; 	// generates a random number (left and right)
	direction = static_cast<Direction>(directionInt);
}
