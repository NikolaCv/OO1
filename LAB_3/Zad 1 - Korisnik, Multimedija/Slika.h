#ifndef SLIKA_H
#define SLIKA_H

#include "myExceptions.h"
#include "Multimedija.h"
#include <string>
#include <iostream>

using namespace std;

class Slika : public Multimedija
{
public:
	Slika(const string& name, unsigned height, unsigned width, unsigned pixel_size);
	string toString() const override;
	string getDescription() const override;
	unsigned getSize() const override;
	Slika* copy() const override;

private:
	unsigned size;
	unsigned width, height, pixel_size;
	string description;

};

#endif