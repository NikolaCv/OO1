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
	Karta(const string& name, int needed_magic_energy);
	Karta(const Karta& card) = delete;
	Karta(Karta&& card) = delete;
	Karta& operator=(const Karta& card) = delete;
	Karta& operator=(Karta&& card) = delete;
	string getName() const;
	unsigned getID() const;
	int getMagicEnergyNeeded() const;
	virtual void upotrebi(Igrac& player1, Igrac& player2) const = 0;
	virtual KATEGORIJA getCategory() const = 0;
	virtual int getStrength() const = 0;
	virtual string toString() const;
	friend ostream& operator<<(ostream & out, const Karta& card);
private:
	string name;
	int magic_energy_needed;
	static unsigned statID;
	unsigned ID = ++statID;
};

#endif