#include "Obavestenje.h"
#include "Korisnik.h"

#include <string>

int Obavestenje::statID = 0;

Obavestenje::~Obavestenje()
{
}

void Obavestenje::readIt()
{
	is_read = true;
}

bool Obavestenje::isRead() const
{
	return is_read;
}

int Obavestenje::getID() const
{
	return ID;
}

Korisnik * Obavestenje::getUser() const
{
	return user;
}

string Obavestenje::toString() const
{
	return "";
}

Obavestenje * Obavestenje::kopija() const
{
	return new Obavestenje(*this);
}

void Obavestenje::addUser(Korisnik * user)
{
	this->user = user;
}

void Obavestenje::kopiraj(const Obavestenje & notification)
{
	user = notification.user;
	is_read = notification.is_read;
}

void Obavestenje::premesti(Obavestenje & notification)
{
	ID = notification.ID;
	user = notification.user;
	notif_time = notification.notif_time;
	is_read = notification.is_read;
}

Obavestenje::Obavestenje(Korisnik * user):user(user)
{
}

Obavestenje::Obavestenje(const Obavestenje & notification)
{
	kopiraj(notification);
}

Obavestenje::Obavestenje(Obavestenje && notification)
{
	premesti(notification);
}

Obavestenje & Obavestenje::operator=(const Obavestenje & notification)
{
	if (this != &notification)
	{
		kopiraj(notification);
	}

	return *this;
}

Obavestenje & Obavestenje::operator=(Obavestenje && notification)
{
	if (this != &notification)
	{
		premesti(notification);
	}

	return *this;
}

ostream & operator<<(ostream & out, const Obavestenje & notification)
{
	struct tm* time = localtime(&notification.notif_time);
	//ako nema korisnika jos uvek, pisem user missing, ako ima pisemo njegovo ime
	string user_str = (notification.user == nullptr) ? "USER MISSING" : notification.user->getName();
	out << notification.ID << "|" << user_str << "-" <<
		time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << "\n" << notification.toString();
	return out;
}
