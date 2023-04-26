#include "Owl.h"

Owl::Owl():Animal()
{
	int directionInt = rand() % 4 + 4;
	direction = static_cast<Direction>(directionInt);
}

Owl::Owl(const std::string& n, const Location& l): Animal(n, l)
{
	int directionInt = rand() % 4 + 4;
	direction = static_cast<Direction>(directionInt);
}

Owl::Owl(const std::string& n) : Animal(n)
{
	int directionInt = rand() % 4 + 4;
	direction = static_cast<Direction>(directionInt);
}

std::string Owl::getType() const
{
	return "Owl";
}

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
	if (isMoving)
	{
		const int MINROWCOL = 2;
		const int MAXROW = 17;
		const int MAXCOL = 37;
		switch (direction)
		{

		case Direction::UpLeft:
			if (location.row > MINROWCOL && location.col > MINROWCOL)
			{
				Location l(-OWLMOVE, -OWLMOVE);
				location += l;
			}
			else
			{
				int directionInt = rand() % 4 + 4;
				direction = static_cast<Direction>(directionInt);
			}
			break;
		case Direction::UpRight:
			if (location.row > MINROWCOL && location.col < MAXCOL)
			{
				Location l(-OWLMOVE, OWLMOVE);
				location += l;
			}
			else
			{
				int directionInt = rand() % 4 + 4;
				direction = static_cast<Direction>(directionInt);
			}
			break;
		case Direction::DownLeft:
			if (location.row < MAXROW && location.col > MINROWCOL)
			{
				Location l(OWLMOVE, -OWLMOVE);
				location += l;
			}
			else
			{
				int directionInt = rand() % 4 + 4;
				direction = static_cast<Direction>(directionInt);
			}
			break;
		case Direction::DownRight:
			if (location.row < MAXROW && location.col < MAXCOL)
			{
				Location l(OWLMOVE, OWLMOVE);
				location += l;
			}
			else
			{
				int directionInt = rand() % 4 + 4;
				direction = static_cast<Direction>(directionInt);
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
}
