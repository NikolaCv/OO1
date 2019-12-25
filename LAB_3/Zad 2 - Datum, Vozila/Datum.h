#ifndef DATUM_H
#define DATUM_H
#include <iostream>
#include <string>
#include "myExceptions.h"

using namespace std;

//TODO: exceptions za prestupne godine, 50 januar itd.

class Datum
{
public:
	Datum();
	Datum(int day, int month, int year);
	Datum(const Datum& day) = default;
	Datum(Datum&& day) = default;
	Datum& operator=(const Datum& day) = default;
	Datum& operator=(Datum&& day) = default;
	int operator[](const string& str) const;
	friend bool operator<(const Datum& date1, const Datum& date2);
	friend bool operator>(const Datum& date1, const Datum& date2);
	friend unsigned operator-(const Datum& date1, const Datum& date2);//TODO ova funkcija i exception za nju
	friend ostream& operator<<(ostream &out, const Datum& d);
private:
	int day, month, year;
	int numOfLeapYears(const Datum&) const;
};

#endif
