#include "Datum.h"

Datum::Datum()
{
	day = 28;
	month = 12;
	year = 2019;
}

Datum::Datum(int day, int month, int year) :day(day), month(month), year(year)
{
	
}

bool Datum::isLeapYear() const
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) ? true : false;
}

int Datum::operator[](const string & s) const
{
	if (s != "dan" && s != "mesec" && s != "godina") throw myExceptions::InvalidDateIndexException();
	
	if (s == "dan") return day;
	if (s == "mesec") return month;
	if (s == "godina") return year;
}

bool operator<(const Datum& date1, const Datum& date2)
{
	if (to_string(date1.day) + to_string(date1.month) + to_string(date1.year)
		< to_string(date2.day) + to_string(date2.month) + to_string(date2.year))
		return true;
	return false;
}

bool operator>(const Datum& date1, const Datum& date2)
{
	if (to_string(date1.day) + to_string(date1.month) + to_string(date1.year)
		> to_string(date2.day) + to_string(date2.month) + to_string(date2.year))
		return true;
	return false;
}

unsigned operator-(const Datum & date1, const Datum & date2)
{
	//julijanski algoritam

	return 0;
}

ostream & operator<<(ostream & out, const Datum & d)
{
	out << d.day << "." << d.month << "." << d.year << ".";
	return out;
}
