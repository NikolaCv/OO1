#include "Datum.h"

Datum::Datum()
{
	day = 28;
	month = 12;
	year = 2019;
}

Datum::Datum(int day = 28, int month = 12, int year = 2019) :day(day), month(month), year(year)
{
}

int Datum::operator[](const string & s) const
{
	if (s != "dan" && s != "mesec" && s != "godina") throw myExceptions::InvalidDateIndexException();
	
	if (s == "dan") return day;
	if (s == "mesec") return month;
	if (s == "godina") return year;
}

int Datum::numOfLeapYears(const Datum & date) const
{
	if ((*this) < date) throw myExceptions::FirstDateIsBeforeSecondException();
	int s = 0;
	for (int i = date.year; i <= year; ++i)
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))//ako je prestupna
		{
			if (i == date.year && date.month <= 2)//ako je pocetna, ako je pre 2. meseca dodajemo 1 dan
				s++;

			else if (i == year && (month > 2 || (month == 2 && day == 29)))//ako je krajnja, ako je posle drugog, ili je bas 29. feb dodajemo 1 dan
				s++;
			//u suprotnom dodajemo jedan dan jer je prestupna
			s++;
		}

	return s;
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
	int days = date1.numOfLeapYears(date2);
	days += (date1.year - date2.year) * 365;
	if (date1.month - date2.month < 0)
	{
		days -= 365;
		days += (date1.month - date2.month + 12) * 30;	//ne valja jer nema svaki mesec 30 dana.........
	}
	if (date1.day - date2.day < 0)
	{
		days -= 30;
		days += (date1.day - date2.day + 30);	//ne valja jer nema svaki mesec 30 dana.........
	}

	return days;
}

ostream & operator<<(ostream & out, const Datum & d)
{
	out << d.day << "." << d.month << "." << d.year << ".";
	return out;
}
