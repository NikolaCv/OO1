#ifndef UREDJAJ_H
#define UREDJAJ_H

#include <iostream>
#include <string>
#include "Garancija.h"

using namespace std;

class Uredjaj
{
public:
	Uredjaj(string name, int max_broj_kvarova);
	Uredjaj(const Uredjaj& uredjaj) = delete;
	Uredjaj(Uredjaj&& uredjaj) = delete;
	Uredjaj& operator=(const Uredjaj& uredjaj) = delete;
	Uredjaj& operator=(Uredjaj&& uredjaj) = delete;
	virtual void setGarancija(Datum* d) = 0;
	Garancija* getGarancija() const;
	bool operator==(const Uredjaj& uredjaj) const;
	bool operator!=(const Uredjaj& uredjaj) const;
	friend ostream& operator<<(ostream &out, const Uredjaj& uredjaj);
	virtual string toString() const;
	~Uredjaj();
	void addKvar(Kvar* kvar);
protected:
	int max_kvarova;
	Garancija* garancija;
	string proizvodjac;
	int id = ++statID;
private:
	static int statID;
};

#endif