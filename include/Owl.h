#pragma once
#include "Animal.h"
class Owl : public Animal {
	static const int OWLMOVE = 3;

public:

	Owl();
	Owl(const std::string& n, const Location& l);
	Owl(const std::string& n);

	void printDetails() const override;
	char getInitial() const override;
	void step() override;
	void turnVertically() override;
	void turnHorizontally() override;
	void move() override;
};