#include "Stajaliste.h"
#include "Gradska_linija.h"

Stajaliste::Stajaliste(int tag, const string & name, int zone):tag(tag),zone(zone),name(name)
{
}

Stajaliste::~Stajaliste()
{
	for (lines.moveCurrentAtStart(); lines.doesCurrentExist(); lines.moveCurrent())
		lines.getCurrentData()->removeStation(*this);
}

int Stajaliste::getTag() const
{
	return tag;
}

int Stajaliste::getZone() const
{
	return zone;
}

string Stajaliste::getName() const
{
	return name;
}

const Lista<Gradska_linija*>& Stajaliste::getLines() const
{
	return lines;
}

void Stajaliste::removeLine(Gradska_linija * line)
{
	for(lines.moveCurrentAtStart(); lines.doesCurrentExist(); lines.moveCurrent())
		if (lines.getCurrentData() == line)
		{
			lines.deleteCurrent();
			return;
		}
}

void Stajaliste::addLine(Gradska_linija * line)
{
	lines += line;
}

bool operator==(const Stajaliste & station1, const Stajaliste & station2)
{
	return (station1.tag == station2.tag) ? true : false;
}

bool operator!=(const Stajaliste & station1, const Stajaliste & station2)
{
	return (station1.tag != station2.tag) ? true : false;
}

ostream & operator<<(ostream & out, const Stajaliste & station)
{
	return out << "[" << station.zone << "] #" << station.tag << " - " << station.name;
}
