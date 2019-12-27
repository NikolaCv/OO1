#ifndef DATUM_H
#define DATUM_H
#include <iostream>
#include <string>
#include "myExceptions.h"

using namespace std;

class Datum
{
public:
	Datum();
	Datum(unsigned day, unsigned month, unsigned year);
	Datum(const Datum& day) = default;
	Datum(Datum&& day) = default;
	Datum& operator=(const Datum& day) = default;
	Datum& operator=(Datum&& day) = default;
	~Datum() = default;
	bool isLeapYear() const;

	int JulijanAlgorithm() const;

	unsigned operator[](const string& str) const;
	friend bool operator<(const Datum& date1, const Datum& date2);
	friend bool operator>(const Datum& date1, const Datum& date2);
	friend int operator-(const Datum& date1, const Datum& date2);
	friend ostream& operator<<(ostream &out, const Datum& d);

private:
	unsigned day, month, year;
	static const short month_days[12];
	bool isDateValid() const;


};

#endif
