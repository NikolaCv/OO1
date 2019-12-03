#include "Datum.h"
#include "Kvar.h"
#include "Garancija.h"
#include "Uredjaj.h"
#include "Klima.h"


int main()
{
	Datum *d1 = new Datum(7, 12, 2019);
	Datum *d2 = new Datum(9, 12, 2019);

	cout << (*d2)["dan"] << endl;
	cout << (*d2)["dn"] << endl;

	if (*d1 < *d2)
		cout << *d1 << endl;
	else
		cout << *d2 << endl;

	Kvar *k1 = new Kvar("polomljen", d1);
	Kvar *k2 = new Kvar("elektronika ne valja", d2);

	cout << *k1 << endl << *k2 << endl;

	/*Uredjaj u1("BEKO");
	
	cout << u1 << endl;*/

	Klima kl1("BEKO", 25);
	Klima kl2("BOSCH", 50);

	cout << kl1 << endl << kl2 << endl;

	if (kl1 == kl2)
		cout << "DA" << endl;
	else
		cout << "NE" << endl;

	kl1.setGarancija(d1);

	kl1.addKvar(k2);

	cout << *kl1.getGarancija()->getLastKvar() <<endl;

	cout << *kl1.getGarancija() << endl;

	cout << kl1 << endl;

	system("pause");
	return 0;
}