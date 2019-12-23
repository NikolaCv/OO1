#ifndef EVIDENCIJA_H
#define EVIDENCIJA_H
#include "Lista.h"
#include "Korisnik.h"
#include "Multimedija.h"
#include "Slika.h"


class Evidencija
{
public:
	Evidencija() = default;
	Evidencija(const Evidencija& user) = delete;
	Evidencija(Evidencija&& user) = delete;
	Evidencija& operator=(const Evidencija& user) = delete;
	Evidencija& operator=(Evidencija&& user) = delete;
	~Evidencija() = default;

	Evidencija& operator+=(Korisnik* user);
	Korisnik* operator[](const string name);
	Korisnik operator[](const string name) const;
	void operator()(const string name);
	void changePassword(const string name, const string old_password, const string new_password);

private:
	Lista<Korisnik*> list;

};

#endif