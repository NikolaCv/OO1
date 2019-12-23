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
	Slika(const string name, int height, int width);
	//?????????void setPixelSize(int pixel_size);
	
private:
	int width, height;
	//int pixel_size;
};

#endif