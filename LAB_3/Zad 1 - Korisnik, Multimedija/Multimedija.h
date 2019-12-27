#ifndef MULTIMEDIJA_H
#define MULTIMEDIJA_H

#include "myExceptions.h"
#include <iostream>
#include <string>

using namespace std;


class Multimedija
{
public:
	Multimedija(const string& name);
	Multimedija(const Multimedija& m) = default;
	Multimedija(Multimedija&& m) = default;
	Multimedija& operator=(const Multimedija& m) = default;
	Multimedija& operator=(Multimedija&& m) = default;
	~Multimedija() = default;

	virtual unsigned getSize() const = 0;
	virtual string getDescription() const = 0;
	virtual string toString() const = 0;
	friend ostream& operator<<(ostream & out, const Multimedija& multimedia);
	virtual Multimedija* copy() const = 0;

protected:
	string name;
};

#endif