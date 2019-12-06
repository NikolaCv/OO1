#ifndef KARTA_H
#define KARTA_H
#include <iostream>
#include <string>

using namespace std;

class Igrac;

class Karta
{
public:
	enum KATEGORIJA { CAROLIJA, BORAC };
	Karta(const string name, int needed_magic_energy);
	Karta(const Karta& card) = delete;
	Karta(Karta&& card) = delete;
	Karta& operator=(const Karta& card) = delete;
	Karta& operator=(Karta&& card) = delete;
	string getName() const;
	unsigned getID() const;
	int getMagicEnergyNeeded() const;
	virtual string toString() const;//vraca specifican deo teksta za ispisivanje za ovu klasu. za ovu je prazan, za izvedene vraca nesto
	virtual void upotrebi(Igrac& player2) const = 0;//useCard a.k.a. napadni
	virtual KATEGORIJA getCategory() const = 0;
	virtual int getStrength() const = 0;
	friend ostream& operator<<(ostream & out, const Karta& card);
private:
	string name;
	int magic_energy_needed;
	static unsigned statID;
	unsigned ID = ++statID;
};

#endif