#pragma once
#include "Animal.h"

//class owl
class Owl : public Animal {
	static const int OWLMOVE = 3;

public:
	//Default constructor
	Owl();

	//Parameterized constructor
	Owl(const std::string& n, const Location& l);

	//Parameterized constructor
	Owl(const std::string& n);

	//get type of owl
	std::string getType() const override;

	//print details of owl
	void printDetails() const override;

	//get initial of owl
	char getInitial() const override;

	/// <summary>
	/// Owl steps - fly only diagonally and always 3 steps
	/// </summary>
	void step() override;

	//turn the direction Vertically
	void turnVertically() override;

	//turn the direction horizontally
	void turnHorizontally() override;

	/// <summary>
	/// Returns the owl to flight. The direction is determined randomly
	/// </summary>
	void move() override;
};
