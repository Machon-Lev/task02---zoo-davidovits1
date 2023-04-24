#pragma once
#include "Animal.h"
class Owl : public Animal {
public:

	Owl() : Animal() {};
	Owl(const std::string& n, const Location& l): Animal(n, l) {};

	void printDetails() const override;
	char getInitial() const override;
	void step() override;
	void turnVertically() override;
	void turnHorizontally() override;
};