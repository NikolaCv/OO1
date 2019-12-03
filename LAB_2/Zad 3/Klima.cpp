#include "Klima.h"

Klima::Klima(string name, int broj_kv):Uredjaj(name,2),broj_kvadrata(broj_kv)
{
}

void Klima::setGarancija(Datum * d)
{
	Datum *d1 = new Datum((*d)["dan"], (*d)["mesec"], (*d)["godina"] + 5);
	garancija = new Garancija(d, d1);
}

string Klima::toString() const
{
	return proizvodjac + ":" + to_string(id) + "#klima#-" + to_string(broj_kvadrata);
}

bool Klima::operator==(const Klima & k) const
{
	if (proizvodjac == k.proizvodjac && broj_kvadrata == k.broj_kvadrata)
		return true;
	return false;
}

bool Klima::operator!=(const Klima & k) const
{
	if (proizvodjac == k.proizvodjac && broj_kvadrata == k.broj_kvadrata)
		return false;
	return true;
}
