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

	}
}

void Owl::turnVertically()
{
}

void Owl::turnHorizontally()
{
}
