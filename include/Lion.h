#pragma once
#include "Animal.h"
class Lion : public Animal {
	static const int LIONMOVE = 2;

public:

	Lion();
	Lion(const std::string& n, const Location& l);
	Lion(const std::string& n);
	std::string getType() const override;
	void printDetails() const override;
	char getInitial() const override;
	void step() override;
	void turnVertically() override;
	void turnHorizontally() override;
	void move() override;
};