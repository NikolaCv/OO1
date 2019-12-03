#include "Uredjaj.h"

int Uredjaj::statID = 0;

string Uredjaj::toString() const
{
	return proizvodjac + ":" + to_string(id);
}

Uredjaj::~Uredjaj()
{
	delete garancija;
}

void Uredjaj::addKvar(Kvar * k)
{
	garancija->dodajKvar(k);
}

Uredjaj::Uredjaj(string name, int max_broj_kvarova):proizvodjac(name),max_kvarova(max_broj_kvarova), garancija(nullptr)
{
}

Garancija * Uredjaj::getGarancija() const
{
	return garancija;
}

bool Uredjaj::operator==(const Uredjaj & u) const
{
	if (proizvodjac == u.proizvodjac)
		return true;
	return false;
}

bool Uredjaj::operator!=(const Uredjaj & u) const
{
	if (proizvodjac == u.proizvodjac)
		return false;
	return true;
}

ostream & operator<<(ostream & out, const Uredjaj & u)
{
	out << u.toString();
	return out;

}
