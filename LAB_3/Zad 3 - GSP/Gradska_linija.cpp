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

void Gradska_linija::removeStation(const Stajaliste & station)
{
	for (stations.moveCurrentAtStart(); stations.doesCurrentExist(); stations.moveCurrent())
		if (stations.getCurrentData() == &station)
		{
			stations.deleteCurrent();
			break;
		}
}

int operator&(const Gradska_linija & line1, const Gradska_linija & line2)
{
	int s = 0;

	for (line1.stations.moveCurrentAtStart(); line1.stations.doesCurrentExist(); line1.stations.moveCurrent())
	{
		for (line2.stations.moveCurrentAtStart(); line2.stations.doesCurrentExist(); line2.stations.moveCurrent())
			if (*line1.stations.getCurrentData() == *line2.stations.getCurrentData())
				s++;
	}

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
