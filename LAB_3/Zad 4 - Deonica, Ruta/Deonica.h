#ifndef DEONICA_H
#define DEONICA_H

#include "myExceptions.h"
#include "Mesto.h"

class Deonica//TODO
{
public:
	enum KATEGORIJA_PUTA { MAGISTRALNI, AUTOPUT };
	enum KATEGORIJA_VOZILA { LAKO, TESKO };
	Deonica(Mesto* start_place, Mesto* end_place, KATEGORIJA_PUTA category);
	Deonica(const Deonica& line);
	Deonica(Deonica&& line);
	Deonica& operator=(const Deonica& line);
	Deonica& operator=(Deonica&& line);
	~Deonica();

	Mesto* getStartPlace() const;
	Mesto* getEndPlace() const;
	double operator~() const;
	double operator()(KATEGORIJA_VOZILA category);

	friend ostream& operator<<(ostream& out, const Deonica& section);

private:
	Mesto* start_place, *end_place;
	KATEGORIJA_PUTA category;
};

#endif