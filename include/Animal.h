#pragma once
class Animal {
protected:
	bool mooving = true;

public:
	void printDetails() const;
	char getInitial() const;
	Location getLocation() const;
	virtual void step() = 0;
	void stop();
	virtual void move() = 0;
	virtual void turnVertically();
	virtual void turnHorizontally();
};