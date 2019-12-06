#include "Korisnik.h"
#include <string>

Korisnik::Korisnik(const string& name):name(name)
{
}

void Korisnik::receive(Obavestenje * notification)
{
	list += notification;
	notification->addUser(this);
}

string Korisnik::getName() const
{
	return name;
}

void Korisnik::send(Obavestenje * notification, Korisnik* user) const
{
	user->receive(notification);
}

ListaObavestenja& Korisnik::getNotifications()
{
	return list;
}

ostream & operator<<(ostream & out, const Korisnik& user)
{
	out << user.name<< endl << user.list;
	return out;
}
