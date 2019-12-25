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
	Deonica(const Deonica& section);
	Deonica(Deonica&& section);					//default? ili delete? jer necemo da pravimo novo mesto???
	Deonica& operator=(const Deonica& section);	//ako brisemo deonicu necemo da obrisemo i mesto, jer mozda mesto pripada drugim deonicama?
	Deonica& operator=(Deonica&& section);
	~Deonica();

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