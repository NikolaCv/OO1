#ifndef KORISNIK_H
#define KORISNIK_H

#include "ListaObavestenja.h"

class Korisnik
{
public:
	Korisnik(const string& name);
	Korisnik(const Korisnik& user) = delete;
	Korisnik(Korisnik&& user) = delete;
	Korisnik& operator=(const Korisnik& user) = delete;
	Korisnik& operator=(Korisnik&& user) = delete;
	void receive(Obavestenje * notification);
	void send(Obavestenje * notification, Korisnik* user) const;
	string getName() const;
	ListaObavestenja& getNotifications();//vraca listu obavestenja
	friend ostream& operator<<(ostream &out, const Korisnik& user);

private:
	string name;
	ListaObavestenja list;
};

#endif