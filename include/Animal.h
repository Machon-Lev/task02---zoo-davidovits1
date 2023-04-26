#pragma once
#include <iostream>
#include <string>
#include "Location.h"
#include "Direction.h"

/// <summary>
/// Pure abstract Animal class
/// </summary>
class Animal {
protected:
	bool isMoving = true;
	std::string name;
	Location location;
	Direction direction;
	
public:
	/// <summary>
	/// Random location - row between 0 and 19 and column between 0 and 39
	/// </summary>
	/// <returns>random location</returns>
	static Location random();

	/// <summary>
	/// Default constructor
	/// </summary>
	Animal(): location() {};

	/// <summary>
	/// Parameterized constructor
	/// </summary>
	/// <param name="n">name of animal</param>
	/// <param name="l">location of animal</param>
	Animal(const std::string& n, const Location& l) : name(n), location(l) {}

	/// <summary>
	/// Parameterized constructor
	/// </summary>
	/// <param name="n">name of animal</param>
	Animal(const std::string& n);

	/// <summary>
	/// return isMoving
	/// </summary>
	/// <returns>isMoveing</returns>
	bool getIsMoving();

	/// <summary>
	/// print deatails of animal
	/// </summary>
	virtual void printDetails() const;

	/// <summary>
	/// pure abstract - char of first type animal
	/// </summary>
	/// <returns>char of first type animal</returns>
	virtual char getInitial() const = 0;

	/// <summary>
	/// get location of animal
	/// </summary>
	/// <returns>location</returns>
	Location getLocation() const;

	/// <summary>
	/// get name of animal
	/// </summary>
	/// <returns></returns>
	virtual std::string getName() const;

	/// <summary>
	/// pure abstract - get type of animal
	/// </summary>
	/// <returns>string type animal</returns>
	virtual std::string getType() const = 0;

	/// <summary>
	/// get direction of animal
	/// </summary>
	/// <returns>direction</returns>
	virtual Direction getDirection() const;

	/// <summary>
	/// pure abstract - step animal
	/// </summary>
	virtual void step() = 0;

	/// <summary>
	/// stop steps of animal
	/// </summary>
	void stop();

	/// <summary>
	/// returns the animal to step
	/// </summary>
	virtual void move();

	/// <summary>
	/// pure abstract - turn the direction vertically
	/// </summary>
	virtual void turnVertically() = 0;

	/// <summary>
	/// pure abstract - turn the direction horizontally
	/// </summary>
	virtual void turnHorizontally() = 0;

};
// Printing operator (<<)
std::ostream& operator<<(std::ostream& os, Direction dir);
