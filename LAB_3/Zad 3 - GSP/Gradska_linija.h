#ifndef GRADSKA_LINIJA_H
#define GRADSKA_LINIJA_H

#include "myExceptions.h"
#include "Lista.h"
#include "Stajaliste.h"


class Gradska_linija
{
public:
	Gradska_linija(const string& text_tag, Lista<Stajaliste*>& list);
	Gradska_linija(const Gradska_linija& line) = default;
	Gradska_linija(Gradska_linija&& line) = default;
	Gradska_linija& operator=(const Gradska_linija& line) = default;
	Gradska_linija& operator=(Gradska_linija&& line) = default;
	~Gradska_linija();

	void removeStation(const Stajaliste& station);
	friend int operator&(const Gradska_linija& line1, const Gradska_linija& line2);

	friend ostream& operator<<(ostream& out, const Gradska_linija& line);

private:
	string text_tag;
	Lista<Stajaliste*> stations;//pokazivac ili referenca?

};

#endif