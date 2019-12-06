#include "Garancija.h"

Garancija::Garancija(Datum * poc, Datum * kr):pocetak(poc),kraj(kr)
{
	prvi = nullptr;
	posl = nullptr;
	len = 0;
}

Garancija::Garancija(const Garancija & g)
{
	kopiraj(g);
}

Garancija::Garancija(Garancija && g)
{
	premesti(g);
}

Garancija & Garancija::operator=(const Garancija & g)
{
	if (this != &g)
	{
		brisi();
		kopiraj(g);
	}

	return *this;
}

Garancija & Garancija::operator=(Garancija && g)
{
	if (this != &g)
	{
		brisi();
		premesti(g);
	}

	return *this;
}

Garancija::~Garancija()
{
	brisi();
}

void Garancija::dodajKvar(Kvar* k)
{
	if (uslovDodavanjaKvara(k))
	{
		Lista* novi = new Lista(k);
		if (posl != nullptr)
		{
			posl->next = novi;
			posl = novi;
		}
		else
		{
			prvi = posl = novi;
		}
		len++;
	}

}

bool Garancija::uslovDodavanjaKvara(Kvar * k)
{
	if (posl == nullptr)
		return true;
	if (*k->getDate() < *kraj && posl->kvar->getInfo())
		return true;

	return false;
}

Kvar * Garancija::getLastKvar()
{
	if(posl != nullptr)
		return posl->kvar;
	exit(2);
}

int Garancija::getNumKvar()
{
	return len;
}

void Garancija::brisi()
{
	while (prvi)
	{
		Lista *tek = prvi;
		prvi = prvi->next;
		delete tek;
	}
	posl = nullptr;
}

void Garancija::kopiraj(const Garancija & g)
{
	Lista* tek = g.prvi;
	while (tek)
	{
		Lista* novi = new Lista(tek->kvar->kopija());
		if (prvi == nullptr)
			prvi = novi;
		else
			posl->next = novi;
		posl = novi;
		tek = tek->next;
	}
	len = g.len;
}

void Garancija::premesti(Garancija & g)
{
	prvi = g.prvi;
	posl = g.posl;
	len = g.len;
	g.prvi = g.posl = nullptr;
}

ostream & operator<<(ostream & out, const Garancija & g)
{
	out << *g.pocetak << "-" << *g.kraj << "-broj kvarova:" << g.len;
	return out;
}
