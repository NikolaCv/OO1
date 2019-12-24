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
	~Stajaliste() = default;

	int getTag() const;
	int getZone() const;
	string getName() const;
	friend bool operator==(const Stajaliste& station1, const Stajaliste& station2);
	friend bool operator!=(const Stajaliste& station1, const Stajaliste& station2);

	friend ostream& operator<<(ostream& out, const Stajaliste& station);

private:
	int tag, zone;
	string name;
	Lista<Gradska_linija*> lines;//kada se brise lines, brisu se i gradske linije, treba promeniti to, posto imaju oznaku onda
	//ova lista nema operator() za brisanje, tako da zasto ne bi samo ne brisao iz liste, nego rucno u mainu
	//isto i za automobile listu
	//za evidenciju neka ostane jer ima operator()?
	//u sustini najbolje je i bez pokazivaca u prvoj
};

#endif