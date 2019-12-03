#ifndef GARANCIJA_H
#define GARANCIJA_H

#include <iostream>
#include "Kvar.h"


class Garancija
{
public:
	Garancija(Datum* pocetni, Datum* krajnji);
	Garancija(const Garancija& garancija);
	Garancija(Garancija&& garancija);
	Garancija& operator=(const Garancija& garancija);
	Garancija& operator=(Garancija&& garancija);
	~Garancija();
	void dodajKvar(Kvar* kvar);
	bool uslovDodavanjaKvara(Kvar* kvar);
	Kvar* getLastKvar();
	int getNumKvar();
	friend ostream& operator<<(ostream& out, const Garancija& garancija);
private:
	struct Lista
	{
		Kvar* kvar;
		Lista* next;
		Lista(Kvar* k) : next(nullptr)
		{
			kvar = k;
		}
	};
	int len;
	Lista *prvi, *posl;
	Datum* pocetak, *kraj;
	void brisi()
	{
		while (prvi)
		{
			Lista *tek = prvi;
			prvi = prvi->next;
			delete tek;
		}
		posl = nullptr;
	}
	void kopiraj(const Garancija& g)
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
	void premesti(Garancija& g)
	{
		prvi = g.prvi;
		posl = g.posl;
		len = g.len;
		g.prvi = g.posl = nullptr;
	}
};

#endif