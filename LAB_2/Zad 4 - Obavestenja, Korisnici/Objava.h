#ifndef OBJAVA_H
#define OBJAVA_H

#include "Obavestenje.h"

class Objava: public Obavestenje
{
public:
	Objava(Korisnik* user, const string text);
	string toString() const override;
private:
	string text;
};

#endif