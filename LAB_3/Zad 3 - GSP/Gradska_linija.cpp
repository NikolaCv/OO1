#include "Gradska_linija.h"

Gradska_linija::Gradska_linija(const string & text_tag, Lista<Stajaliste*> list):text_tag(text_tag),stations(list)
{
}

int operator&(const Gradska_linija & line1, const Gradska_linija & line2)
{
	int s = 0;

	return s;
}

ostream & operator<<(ostream & out, const Gradska_linija & line)
{
	return out << line.text_tag << endl << line.stations;
}
