#ifndef STAJALISTE_H
#define STAJALISTE_H

#include "myExceptions.h"
#include "Lista.h"

class Gradska_linija;

class Stajaliste
{
public:
	Stajaliste(int tag, const string& name, int zone);
	Stajaliste(const Stajaliste& station) = default;
	Stajaliste(Stajaliste&& station) = default;
	Stajaliste& operator=(const Stajaliste& station) = default;
	Stajaliste& operator=(Stajaliste&& station) = default;
	~Stajaliste();

	int getTag() const;
	int getZone() const;
	string getName() const;
	const Lista<Gradska_linija*>& getLines() const;
	void removeLine(Gradska_linija* line);

	friend bool operator==(const Stajaliste& station1, const Stajaliste& station2);
	friend bool operator!=(const Stajaliste& station1, const Stajaliste& station2);
	void addLine(Gradska_linija* line);

	friend ostream& operator<<(ostream& out, const Stajaliste& station);

private:
	int tag, zone;
	string name;
	Lista<Gradska_linija*> lines;

};

#endif