#pragma once
#include "Animal.h"
class Lion : public Animal {
public:

	Lion();
	Lion(const std::string& n, const Location& l);

	void printDetails() const override;
	char getInitial() const override;
	void step() override;
	void turnVertically() override;
	void turnHorizontally() override;
	void move() override;
};