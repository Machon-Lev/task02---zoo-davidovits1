#include "Monkey.h"

Monkey::Monkey():Animal()
{
	count = 1;
	numMove = rand() % 2 + 1;
	int directionInt = rand() % 4;
	direction = static_cast<Direction>(directionInt);
}

Monkey::Monkey(const std::string& n, const Location& l):Animal(n, l)
{
	count = 1;
	numMove = rand() % 2 + 1;
	int directionInt = rand() % 4;
	direction = static_cast<Direction>(directionInt);
}

Monkey::Monkey(const std::string& n) : Animal(n)
{
	count = 1;
	numMove = rand() % 2 + 1;
	int directionInt = rand() % 4;
	direction = static_cast<Direction>(directionInt);
}

void Monkey::printDetails() const
{
	std::cout << "Kind: Monkey" << std::endl;
	Animal::printDetails();
}

char Monkey::getInitial() const
{
	return 'M';
}

void Monkey::step()
{
	if (count == 5)
	{
		numMove = rand() % 2 + 1;
		int directionInt = rand() % 4;
		direction = static_cast<Direction>(directionInt);
		count = 1;
	}
	if (isMoving)
	{
		int minRowCol;
		int maxRow;
		int maxCol;
		if (numMove == 1)
		{
			minRowCol = 0;
			maxRow = 19;
			maxCol = 39;
		}
		else
		{
			minRowCol = 1;
			maxRow = 18;
			maxCol = 38;
		}
		switch (direction)
		{
		case Direction::Up:
			if (location.row > minRowCol)
			{
				Location l(-numMove, 0);
				location += l;
			}
			else
			{
				count = 5;
			}
			break;
		case Direction::Down:
			if (location.row < maxRow)
			{
				Location l(numMove, 0);
				location += l;
			}
			else
			{
				count = 5;
			}
			break;
		case Direction::Left:
			if (location.col > minRowCol)
			{
				Location l(0, -numMove);
				location += l;
			}
			else
			{
				count = 5;
			}
			break;
		case Direction::Right:
			if (location.col < maxCol)
			{
				Location l(0, numMove);
				location += l;
			}
			else
			{
				count = 5;
			}
			break;

		default:
			break;
		}

		count++;
	}
}

void Monkey::turnVertically()
{
	switch (direction)
	{
	case Direction::Up:
		direction = Direction::Down;
		break;
	case Direction::Down:
		direction = Direction::Up;
		break;

	default:
		break;
	}
}

void Monkey::turnHorizontally()
{
	switch (direction)
	{
	case Direction::Left:
		direction = Direction::Right;
		break;
	case Direction::Right:
		direction = Direction::Left;
		break;

	default:
		break;
	}
}

