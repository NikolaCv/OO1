#include "Evidencija.h"

Evidencija & Evidencija::operator+=(Korisnik * user)
{
	for (int i = 0; i < list.getLength(); ++i)
		if (list[i] == user) throw myExceptions::UserAlreadyExistsException();

	(this->list) += user;
	return *this;
}

Korisnik * Evidencija::operator[](const string name)
{
	for (int i = 0; i < list.getLength(); ++i)
		if (list[i]->getName() == name)
			return list[i];

	throw myExceptions::UserDoesntExistException();
}

Korisnik Evidencija::operator[](const string name) const
{
	for (int i = 0; i < list.getLength(); ++i)
		if (list[i]->getName() == name)
			return *list[i];

	throw myExceptions::UserDoesntExistException();
}

void Evidencija::operator()(const string name)
{
	for (int i = 0; i < list.getLength(); ++i)
		if (list[i]->getName() == name)
			list(i);

	throw myExceptions::UserDoesntExistException();
}

void Evidencija::changePassword(const string name, const string old_password, const string new_password)
{
	for (int i = 0; i < list.getLength(); ++i)
		if (list[i]->getName() == name)
		{
			list[i]->changePassword(old_password, new_password);
			return;
		}

	throw myExceptions::UserDoesntExistException();
}
