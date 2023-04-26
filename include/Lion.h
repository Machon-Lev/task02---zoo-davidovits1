#pragma once
#include "Animal.h"

/// <summary>
/// class lion
/// </summary>
class Lion : public Animal {
	static const int LIONMOVE = 2;

public:
	///Default constructor
	Lion();

	//Parameterized constructor
	Lion(const std::string& n, const Location& l);

	// Parameterized constructor
	Lion(const std::string& n);

	//get type of lion
	std::string getType() const override;

	//print details of lion
	void printDetails() const override;

	//get initial of lion
 	char getInitial() const override;

	/// <summary>
	/// Lion's steps - move only in the same line and always 2 steps
	/// </summary>
	void step() override;
	
	void turnVertically() override;

	// turn the direction horizontally
	void turnHorizontally() override;

	/// <summary>
	/// Brings the lion back into motion. The direction is determined randomly
	/// </summary>
	void move() override;
};