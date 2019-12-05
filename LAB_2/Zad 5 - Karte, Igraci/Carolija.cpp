#include "Carolija.h"

Carolija::Carolija(const string name, int needed_magic_energy):Karta(name,needed_magic_energy)
{
}
Karta::KATEGORIJA Carolija::getCategory() const
{
	return category;
}
/*		BILO JE POTREBNO ZA TESTIRANJE KLASE CAROLIJA, JER JE BEZ OVOGA APSTRAKTNA
void Carolija::upotrebi(Igrac & player2) const
{
	int a;
}

int Carolija::getStrength() const
{
	return 0;
}
*/