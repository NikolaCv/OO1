#ifndef OBJAVA_H
#define OBJAVA_H

#include "Obavestenje.h"

class Objava: public Obavestenje
{
public:
	Objava(Korisnik* user, const string text);//novi konstruktor, dodatni atribut text
	string toString() const override;//vraca text, koji se koristi u ispisu
private:
	string text;
};

#endif