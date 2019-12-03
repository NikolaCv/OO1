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

ostream & operator<<(ostream & out, const Garancija & g)
{
	out << *g.pocetak << "-" << *g.kraj << "-broj kvarova:" << g.len;
	return out;
}
