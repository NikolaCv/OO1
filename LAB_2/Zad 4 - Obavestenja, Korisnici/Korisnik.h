#ifndef KORISNIK_H
#define KORISNIK_H

#include "ListaObavestenja.h"
//TODO kopija obavestenje i ispisivanje objave teksta
class Korisnik
{
public:
	Korisnik(const string& name);
	Korisnik(const Korisnik& user) = delete;
	Korisnik(Korisnik&& user) = delete;
	Korisnik& operator=(const Korisnik& user) = delete;
	Korisnik& operator=(Korisnik&& user) = delete;
	friend ostream& operator<<(ostream &out, const Korisnik& user);
	void receive(Obavestenje * notification);
	string getName() const;
	void send(Obavestenje * notification, Korisnik* user) const;
	ListaObavestenja& getNotifications();
private:
	string name;
	ListaObavestenja list;
};

#endif