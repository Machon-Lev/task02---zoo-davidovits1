#include "Owl.h"

void Owl::printDetails() const
{
	std::cout << "Kind: Owl" << std::endl;
	Animal::printDetails();

}

char Owl::getInitial() const
{
	return 'O';
}

void Owl::step()
{
	if (mooving)
	{
		switch (direction)
		{

		case Direction::UpLeft:
			if (location.row >= 3 && location.col >= 3)
			{
				Location l(-3, -3);
				location += l;
			}
			break;
		case Direction::UpRight:
			if (location.row >= 3 && location.col <= 36)
			{
				Location l(-3, 3);
				location += l;
			}
			break;
		case Direction::DownLeft:
			if (location.row <= 16 && location.col >= 3)
			{
				Location l(3, -3);
				location += l;
			}
			break;
		case Direction::DownRight:
			if (location.row <= 16 && location.col <= 36)
			{
				Location l(3, 3);
				location += l;
			}
			break;
		default:
			break;
		}

	}

}

void Owl::turnVertically()
{
	switch (direction)
	{
	case Direction::UpLeft:
		direction = Direction::DownLeft;
		break;
	case Direction::UpRight:
		direction = Direction::DownRight;
		break;
	case Direction::DownLeft:
		direction = Direction::UpLeft;
		break;
	case Direction::DownRight:
		direction = Direction::UpRight;
		break;
	default:
		break;
	}
}

void Owl::turnHorizontally()
{
	switch (direction)
	{
	case Direction::UpLeft:
		direction = Direction::UpRight;
		break;
	case Direction::UpRight:
		direction = Direction::UpLeft;
		break;
	case Direction::DownLeft:
		direction = Direction::DownRight;
		break;
	case Direction::DownRight:
		direction = Direction::DownLeft;
		break;
	default:
		break;
	}
}

void Owl::move()
{
	Animal::move();
	int directionInt = rand() % 4 + 4; // generates a random number between 4 and 7
	direction = static_cast<Direction>(directionInt);
	step();
}
