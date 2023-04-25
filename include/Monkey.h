#pragma once
#include "Animal.h"
class Monkey : public Animal {
	int count;
	int numMove;
public:

	Monkey();
	Monkey(const std::string& n, const Location& l);

	void printDetails() const override;
	char getInitial() const override;
	void step() override;
	void turnVertically() override;
	void turnHorizontally() override;
};