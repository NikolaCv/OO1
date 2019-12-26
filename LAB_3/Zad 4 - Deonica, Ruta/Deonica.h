#ifndef DEONICA_H
#define DEONICA_H

#include "myExceptions.h"
#include "Mesto.h"

class Deonica
{
public:
	enum KATEGORIJA_PUTA { MAGISTRALNI, AUTOPUT };
	enum KATEGORIJA_VOZILA { LAKO, TESKO };
	Deonica(Mesto* start_place, Mesto* end_place, KATEGORIJA_PUTA category);
	Deonica(const Deonica& section) = default;
	Deonica(Deonica&& section) = default;					//default jer treba plitka kopija
	Deonica& operator=(const Deonica& section) = default;	//ako brisemo deonicu necemo da obrisemo i mesto, jer mozda mesto pripada drugim deonicama
	Deonica& operator=(Deonica&& section) = default;
	~Deonica() = default;

	Mesto* getStartPlace() const;
	Mesto* getEndPlace() const;
	KATEGORIJA_PUTA getCategory() const;
	double operator~() const;
	double operator()(KATEGORIJA_VOZILA category);

	friend ostream& operator<<(ostream& out, const Deonica& section);

private:
	Mesto* start_place, *end_place;
	KATEGORIJA_PUTA category;

};

#endif