#include "Datum.h"

const short Datum::month_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


Datum::Datum()
{
	day = 28;
	month = 12;
	year = 2019;
}

Datum::Datum(unsigned day, unsigned month, unsigned year) :day(day), month(month), year(year)
{
	if (!isDateValid()) throw myExceptions::InvalidDateFormatException();
}

bool Datum::isDateValid() const
{
	if (month > 0 && month < 13 && day > 0 && day <= (month_days[month - 1] + (month == 2 && isLeapYear())))
		return true;
	return false;
}

bool Datum::isLeapYear() const
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) && year != 0;
}

int Datum::JulijanAlgorithm() const
{
	//copy paste sa neta julijanski algoritam za racunanje broja dana
	return (1461 * (year + 4800 + (month - 14) / 12)) / 4 
		+ (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12
		- (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 + day - 32075;
}

unsigned Datum::operator[](const string & s) const
{
	if (s == "dan") return day;
	if (s == "mesec") return month;
	if (s == "godina") return year;

	throw myExceptions::InvalidDateIndexException();
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

int operator-(const Datum & date1, const Datum & date2)
{
	int d = date1.JulijanAlgorithm() - date2.JulijanAlgorithm();
	if (d < 0)
		throw myExceptions::FirstDateIsBeforeSecondException();
	return d;
}

ostream & operator<<(ostream & out, const Datum & d)
{
	out << d.day << "." << d.month << "." << d.year << ".";
	return out;
}
