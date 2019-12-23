#ifndef MULTIMEDIJA_H
#define MULTIMEDIJA_H

#include "myExceptions.h"
#include <iostream>
#include <string>
using namespace std;

//opis = ?????
//bytes isto sta?
class Multimedija
{
public:
	Multimedija(const string name);
	Multimedija(const Multimedija& user) = default;
	Multimedija(Multimedija&& user) = default;
	Multimedija& operator=(const Multimedija& user) = default;
	Multimedija& operator=(Multimedija&& user) = default;
	~Multimedija() = default;

	friend ostream& operator<<(ostream & out, const Multimedija& multimedia);

protected:
	int bytes;
	string description;

private:
	string name;
};

#endif