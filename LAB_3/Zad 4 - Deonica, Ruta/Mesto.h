#ifndef MESTO_H
#define MESTO_H

#include "myExceptions.h"

class Mesto
{
public:
	Mesto(const string& name, double width, double length);
	Mesto(const Mesto& line) = default;
	Mesto(Mesto&& line) = default;
	Mesto& operator=(const Mesto& line) = default;
	Mesto& operator=(Mesto&& line) = default;
	~Mesto() = default;

	double getWidth() const;
	double getLength() const;
	string getName() const;

	friend double operator-(const Mesto& place1, const Mesto& place2);//TODO
	friend ostream& operator<<(ostream& out, const Mesto& place);

private:
	string name;
	double width, length;
};

#endif