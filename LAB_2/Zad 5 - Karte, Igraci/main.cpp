#include "Karta.h"
#include "Borac.h"
#include "Carobnjak.h"
#include "Carolija.h"
#include "Igrac.h"
#include "Zbirka.h"

#include <iostream>
#include <string>

using namespace std;

void testKarte()
{
	Carobnjak gandalf("gandalf", 100, 1000);
	Carobnjak saruman("saruman", 50, 750);
	cout << gandalf << endl << saruman << endl;
	
	if (gandalf < saruman)
		cout << saruman << endl;
	if (gandalf > saruman)
		cout << gandalf << endl;

	cout << gandalf.getStrength() << endl;


	/*Carolija orikalkosov_pecat("the seal of orichalcos", 250);	APSTRAKTNA KLASA, TESTIRANJE DOK NIJE BILA
	Carolija bacaj_cini("cin1", 20);
	cout << orikalkosov_pecat << endl << bacaj_cini << endl;*/
}

void testZbirke()
{
	Zbirka z1;
	Carobnjak* gandalf = new Carobnjak("gandalf", 100, 750);
	Carobnjak* legolas = new Carobnjak("legolas", 30, 350);
	z1 += gandalf;
	z1 += legolas;

	Zbirka z2;

	Carobnjak* sauron = new Carobnjak("sauron", 200, 1500);
	Carobnjak* saruman = new Carobnjak("saruman", 50, 500);
	
	z2 += sauron;
	z2 += saruman;
	
	cout << z1 << endl << z2 << endl;

	cout << *z1[unsigned(4)] << endl;
	cout << *z1[1] << endl;

	~z2;

	cout << z2 << endl;
	
	z2 = z1;
	Zbirka z3 = z2;

	cout << z3 << endl << z2 << endl;
}

void testIgraci()
{
	Zbirka* z1 = new Zbirka;
	Carobnjak* gandalf = new Carobnjak("gandalf", 100, 750);
	Carobnjak* legolas = new Carobnjak("legolas", 30, 350);
	Carobnjak* oz = new Carobnjak("oz", 10, 150);
	(*z1) += gandalf;
	(*z1) += legolas;
	(*z1) += oz;

	Zbirka* z2 = new Zbirka;

	Carobnjak* sauron = new Carobnjak("sauron", 200, 1500);
	Carobnjak* saruman = new Carobnjak("saruman", 50, 500);
	Carobnjak* ork = new Carobnjak("ork", 10, 200);

	(*z2) += sauron;
	(*z2) += saruman;
	(*z2) += ork;

	cout << *z1 << endl << *z2 << endl;
	
	Igrac nikola("nikola", 4000, 500, z1);
	Igrac andrija("andrija", 4000, 500, z2);

	cout << nikola << endl << andrija << endl;

	nikola.sendCardFromSpilToHand(gandalf); cout << nikola << endl << andrija << endl;
	andrija.sendCardFromSpilToHand(saruman); cout << nikola << endl << andrija << endl;
	nikola.sendCardFromSpilToHand(legolas); cout << nikola << endl << andrija << endl;
	nikola.sendCardFromHandToActivated(gandalf); cout << nikola << endl << andrija << endl;
	andrija.sendCardFromSpilToHand(sauron); cout << nikola << endl << andrija << endl;
	andrija.sendCardFromHandToActivated(saruman); cout << nikola << endl << andrija << endl;

	cout << nikola << endl << andrija << endl;

	nikola.attack(gandalf, andrija);

	cout << nikola << endl << andrija << endl;
}
//TODO:
//testiraj premestanje za zbirke, bool za borce?????? i 

int main()
{
	testKarte();
	testZbirke();
	testIgraci();
	system("pause");
	return 0;
}