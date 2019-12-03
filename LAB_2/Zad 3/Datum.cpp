#include "Datum.h"



Datum::Datum(int day = 30, int month = 11, int year = 2019) :day(day), month(month), year(year)
{
}

int Datum::operator[](const string & s) const
{
	if (s != "dan" && s != "mesec" && s != "godina")
		return -1;
	else
		if (s == "dan")
			return day;
		else
			if (s == "mesec")
				return month;
			else
				return year;
}

bool Datum::operator<(const Datum & d) const
{
	if (to_string(day) + to_string(month) + to_string(year)
		< to_string(d.day) + to_string(d.month) + to_string(d.year))
		return true;
	return false;
}

bool Datum::operator>(const Datum & d) const
{
	if (to_string(day) + to_string(month) + to_string(year)
		> to_string(d.day) + to_string(d.month) + to_string(d.year))
		return true;
	return false;
}

ostream & operator<<(ostream & out, const Datum & d)
{
	out << d.day << "." << d.month << "." << d.year << ".";
	return out;
}
