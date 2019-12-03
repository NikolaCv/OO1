#ifndef DATUM_H
#define DATUM_H
#include <iostream>
#include <string>

using namespace std;

class Datum
{
public:
	Datum(int day, int month, int year);
	Datum(const Datum& day) = default;
	Datum(Datum&& day) = default;
	Datum& operator=(const Datum& day) = default;
	Datum& operator=(Datum&& day) = default;
	int operator[](const string& str) const;
	bool operator<(const Datum& day) const;
	bool operator>(const Datum& day) const;
	friend ostream& operator<<(ostream &out, const Datum& d);
private:
	int day, month, year;
};

#endif // !DATUM_H