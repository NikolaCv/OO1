#include "Evidencija.h"

Evidencija & Evidencija::operator+=(Korisnik * user)
{
	(this->list) += user;
	return *this;
}

Korisnik * Evidencija::operator[](const string name)
{

	return nullptr;
}
