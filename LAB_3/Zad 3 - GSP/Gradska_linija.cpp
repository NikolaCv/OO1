#include "Gradska_linija.h"

Gradska_linija::Gradska_linija(const string & text_tag, Lista<Stajaliste*>& list):text_tag(text_tag),stations(list)
{
	stations.moveCurrentAtStart();
	while (stations.doesCurrentExist())
	{
		(stations.getCurrentData())->addLine(this);
		stations.moveCurrent();
	}
}

int operator&(const Gradska_linija & line1, const Gradska_linija & line2)
{
	int s = 0;

	return s;
}

ostream & operator<<(ostream & out, const Gradska_linija & line)//ispis posebno stations out za *
{
	line.stations.moveCurrentAtStart();
	out << line.text_tag << endl;
	while (line.stations.doesCurrentExist())
	{
		out << *line.stations.getCurrentData() << endl;
		line.stations.moveCurrent();
	}
	return out;
}
