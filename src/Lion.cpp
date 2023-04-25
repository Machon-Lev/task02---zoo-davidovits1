#include "Lion.h"

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
	if (mooving)
	{
		switch (direction)
		{
		case Direction::Left:
			if (location.col >= 2)
			{
				Location l(0, -2);
				location += l;
			}
			else
			{
				direction = Direction::Right;
				if (location.col < 1)
				{
					Location l(0, 2);
					location += l;
				}
			}
			break;
		case Direction::Right:
			if (location.col <= 37)
			{
				Location l(0, 2);
				location += l;
			}
			else
			{
				direction = Direction::Left;
				if (location.col > 38)
				{
					Location l(0, -2);
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
	// generates a random number between (left and right)
	int directionInt = rand() % 2 + 2; 
	direction = static_cast<Direction>(directionInt);
	step();
}
