#ifndef POLJE_H
#define POLJE_H
#include <iostream>
#include <string>

using namespace std;

class Polje
{
public:
	Polje();
	Polje(int blockage);
	Polje(const Polje&) = default;
	Polje(Polje&&) = default;
	Polje& operator=(const Polje& p) = default;
	Polje& operator=(Polje&& p) = default;
	Polje& operator++();
	Polje& operator--();
	Polje& operator+=(int a);
	Polje& operator-=(int a);
	friend ostream& operator<<(ostream& out, const Polje& p);
	int getPathBlockage();
	virtual string toString() const;
	virtual Polje* kopija() const;
protected:
	int path_blockage;
	char tag;

};

#endif