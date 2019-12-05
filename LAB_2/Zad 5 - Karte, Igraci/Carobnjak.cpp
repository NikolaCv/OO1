#include "Carobnjak.h"
#include "Zbirka.h"
#include "Igrac.h"

Carobnjak::~Carobnjak()
{
}

void Carobnjak::upotrebi(Igrac & player1, Igrac & player2) const
{
	Zbirka* z = player2.getAktivirane();

	int min_strength = INT_MAX;
	int ind = -1;

	for (int i = 0; i < z->getLength(); ++i)
	{
		if ((*z)[i]->getCategory() == BORAC && (*z)[i]->getStrength() < min_strength)//ako je karta borac, i ako je najmanja min postaje ona
		{
			min_strength = (*z)[i]->getStrength();
			ind = i;
		}
	}

	player2.decreaseHP = 2 * getStrength();

	if (ind == -1)
		return;

	
	//player2.//TODO iz aktivirane prebaci u groblje
}

string Carobnjak::toString() const
{
	return Borac::toString() + " - CAROBNJAK";
}