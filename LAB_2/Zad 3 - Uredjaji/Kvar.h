#ifndef KVAR_H
#define KVAR_H

#include <iostream>
#include <string>
#include "Datum.h"

using namespace std;

class Kvar
{
public:
	Kvar(const string& opis_kvara, Datum* datum);
	Kvar(const Kvar& kvar);
	Kvar(Kvar&& kvar);
	Kvar& operator=(const Kvar& kvar);
	Kvar& operator=(Kvar&& kvar);
	~Kvar();
	string getFaliure() const;
	Datum* getDate() const;
	bool getInfo() const;
	void setInfo(bool info);
	friend ostream& operator<<(ostream& out, const Kvar& kvar);
	Kvar* kopija();
private:
	string faliure;
	Datum* date;
	bool uklonjen;
	void kopiraj(const Kvar& k);
	void premesti(const Kvar& k);
	void brisi();
};

#endif