#ifndef KLIMA_H
#define KLIMA_H

#include "Uredjaj.h"

class Klima : public Uredjaj
{
public:
	Klima(string name, int broj_kv);
	void setGarancija(Datum* d) override;
	string toString() const override;
	bool operator==(const Klima& kvar) const;
	bool operator!=(const Klima& kvar) const;
private:
	int broj_kvadrata;
};

#endif