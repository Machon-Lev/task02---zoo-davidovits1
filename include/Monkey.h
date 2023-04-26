#pragma once
#include "Animal.h"

//class monkey
class Monkey : public Animal {
	int count;
	int numMove;
public:
	//Default constructor
	Monkey();

	//Parameterized constructor
	Monkey(const std::string& n, const Location& l);

	//Parameterized constructor
	Monkey(const std::string& n);

	//get type of monkey
	std::string getType() const override;

	//print details of monkey
	void printDetails() const override;

	//get initial of monkey
	char getInitial() const override;

	/// <summary>
	/// Monkey's steps - move one or two steps up, down, right or left.
	///  The number of steps and the direction will be randomized once every 5 steps
	/// </summary>
	void step() override;

	//turn the direction vertically
	void turnVertically() override;

	//turn the direction horizontally
	void turnHorizontally() override;
};
