#include "Kvar.h"

Kvar::Kvar(const string & faliure, Datum * date) :faliure(faliure), date(date)
{
	uklonjen = false;
}

Kvar::Kvar(const Kvar & k)
{
	faliure = k.faliure;
	date = new Datum(*k.date);
	uklonjen = k.uklonjen;
}

Kvar::Kvar(Kvar && k)
{
	premesti(k);
}

Kvar & Kvar::operator=(const Kvar & k)
{
	if (this != &k)
	{
		brisi();
		kopiraj(k);
	}

	return *this;
}

Kvar & Kvar::operator=(Kvar && k)
{
	if (this != &k)
	{
		brisi();
		premesti(k);
	}

	return *this;
}

Kvar::~Kvar()
{
	brisi();
}

string Kvar::getFaliure() const
{
	return faliure;
}

Datum * Kvar::getDate() const
{
	return date;
}

bool Kvar::getInfo() const
{
	return uklonjen;
}

void Kvar::setInfo(bool info)
{
	uklonjen = info;
}

Kvar * Kvar::kopija()
{
	return new Kvar(*this);
}

void Kvar::kopiraj(const Kvar & k)
{
	faliure = k.faliure;
	date = new Datum(*k.date);
	uklonjen = k.uklonjen;
}

void Kvar::premesti(const Kvar & k)
{
	faliure = k.faliure;
	date = k.date;
	uklonjen = k.uklonjen;
}

void Kvar::brisi()
{
	delete date;
}

ostream & operator<<(ostream & out, const Kvar & k)
{
	out << *k.date <<"\t"<< k.faliure;
	return out;
}
