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
	Evidencija(const Evidencija& record) = delete;
	Evidencija(Evidencija&& record) = delete;
	Evidencija& operator=(const Evidencija& record) = delete;
	Evidencija& operator=(Evidencija&& record) = delete;
	~Evidencija() = default;

	Evidencija& operator+=(const Korisnik& user);
	Korisnik& operator[](const string& name);
	const Korisnik& operator[](const string& name) const;
	void operator()(const string& name);
	void changePassword(const string& name, const string& old_password, const string& new_password);
	friend ostream& operator<<(ostream& out, const Evidencija& record);

private:
	Lista<Korisnik> list;

};

#endif