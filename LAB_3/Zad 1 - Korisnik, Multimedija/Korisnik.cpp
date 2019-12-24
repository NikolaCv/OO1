#include "Korisnik.h"

Korisnik::Korisnik(const string& name, const string& password) :name(name), password(password)
{
	checkPasswordFormat(password);
}

void Korisnik::changePassword(const string& old_password, const string& new_password)
{
	if (old_password != password) throw myExceptions::IncorrectPasswordException();

	checkPasswordFormat(new_password);
}

string Korisnik::getName() const
{
	return name;
}

string Korisnik::getPassword() const
{
	return password;
}

void Korisnik::checkPasswordFormat(const string password)
{
	if (password.length() < 8) throw myExceptions::BadPassFormatException();

	bool alpha = false, numeric = false;
	for (int i = 0; i < password.length(); ++i)
	{
		if (isdigit(password[i])) numeric = true;
		else if (isalpha(password[i])) alpha = true;

		if (alpha && numeric) return;
	}

	throw myExceptions::BadPassFormatException();
}

bool operator==(const Korisnik & user1, const Korisnik & user2)
{
	return user1.name == user2.name;
}

bool operator!=(const Korisnik & user1, const Korisnik & user2)
{
	return user1.name != user2.name;
}

ostream & operator<<(ostream & out, const Korisnik & user)
{
	return out << user.name;
}
