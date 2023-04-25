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
		switch (dirction)
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
	switch (dirction)
	{
	case Direction::UpLeft:
		dirction = Direction::DownLeft;
		break;
	case Direction::UpRight:
		dirction = Direction::DownRight;
		break;
	case Direction::DownLeft:
		dirction = Direction::UpLeft;
		break;
	case Direction::DownRight:
		dirction = Direction::UpRight;
		break;
	default:
		break;
	}
}

void Owl::turnHorizontally()
{
	switch (dirction)
	{
	case Direction::UpLeft:
		dirction = Direction::UpRight;
		break;
	case Direction::UpRight:
		dirction = Direction::UpLeft;
		break;
	case Direction::DownLeft:
		dirction = Direction::DownRight;
		break;
	case Direction::DownRight:
		dirction = Direction::DownLeft;
		break;
	default:
		break;
	}
}

void Owl::move()
{
	Animal::move();
	int directionInt = rand() % 5 + 4; // generates a random number between 4 and 8
	dirction = static_cast<Direction>(directionInt);
	step();
}
