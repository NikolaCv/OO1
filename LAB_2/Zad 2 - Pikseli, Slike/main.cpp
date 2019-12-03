#include <iostream>
#include "Piksel.h"
#include "Pozicija.h"
#include "Slika.h"
#include "CBSlika.h"

using namespace std;

int main()
{
	Piksel *p1 = new Piksel(255, 0, 0);
	Piksel *p2 = new Piksel(0, 255, 0);
	Piksel *p3 = new Piksel(0, 0, 255);
	cout << *p3 << endl;

	cout << *p1 << endl << *p2 << endl << *p3 << endl;
	Piksel *p4 = (*p1 + *p2).kopija();

	Piksel *p5 = new Piksel(100, 150, 50);
	Piksel *p6 = new Piksel(79, 255, 100);
	Piksel *p7 = new Piksel(85, 95, 200);
	Piksel *p8 = new Piksel(180, 182, 114);
	Piksel *p9 = new Piksel(50, 254, 0);

	Pozicija poz1(0, 0);
	Pozicija poz2(0, 1);
	Pozicija poz3(0, 2);
	Pozicija poz4(1, 0);
	Pozicija poz5(1, 1);
	Pozicija poz6(1, 2);
	Pozicija poz7(2, 0);
	Pozicija poz8(2, 1);
	Pozicija poz9(2, 2);

	Slika s1(3, 3);
	s1.postaviPiksel(poz1, p1);
	s1.postaviPiksel(poz2, p2);
	s1.postaviPiksel(poz3, p3);
	s1.postaviPiksel(poz4, p4);
	s1.postaviPiksel(poz5, p5);
	s1.postaviPiksel(poz6, p6);
	s1.postaviPiksel(poz7, p7);
	s1.postaviPiksel(poz8, p8);
	s1.postaviPiksel(poz9, p9);


	cout << endl << s1 << endl;

	cout << *s1[poz2] << endl;

	Piksel* p10 = new Piksel(1, 1, 150);

	s1.postaviPiksel(poz5, p10);	//piksel sa pozicije 5, p5, se brise!

	cout << endl << "S1:"<<endl << s1 << endl;
	
	Slika s2 = s1;

	Piksel *p20 = new Piksel(15, 150, 250);

	s2.postaviPiksel(poz8, p20);

	cout << "S2:" << endl << s2<<endl;

	CBSlika crnobelo = s1;

	cout << "crnobelo:" << endl << crnobelo << endl;
	
	CBSlika c2 = crnobelo;

	Piksel *p11 = new Piksel(1, 1, 150);

	c2.postaviPiksel(poz5, p11);

	cout << "c2:" << endl << c2 << endl;
	
	c2 = s2;

	cout << "c2:" << endl << c2 << endl;

	system("pause");
	return 0;
}