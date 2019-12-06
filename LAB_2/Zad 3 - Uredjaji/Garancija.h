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
	void brisi();
	void kopiraj(const Garancija& g);
	void premesti(Garancija& g);

};

#endif