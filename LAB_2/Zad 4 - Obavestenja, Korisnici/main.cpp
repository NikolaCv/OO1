#include <iostream>
#include "Obavestenje.h"
#include "Objava.h"
#include "Korisnik.h"
#include "ListaObavestenja.h"

void testObavestenje() {
	Obavestenje o1(nullptr);
	Obavestenje o2(nullptr);
	Obavestenje o3(o2);
	Obavestenje o4 = Obavestenje(nullptr);
	o3 = o1;
	o2 = Obavestenje(nullptr);
	std::cout << o1 << endl;
	std::cout << o2 << endl;
	std::cout << o3 << endl;
	std::cout << o4 << endl;
	std::cout << o1.getID() << std::endl;
	std::cout << (o1.getUser() == nullptr) << std::endl;
	std::cout << o1.isRead() << std::endl;
}

void testObjava() {
	Objava o1(nullptr, "Andrija vas je bocnuo.");
	Objava o2(nullptr, "Banovani ste sa platforme.");
	Objava o3 = o2;
	Objava o4 = Objava(nullptr, "Napustite prostoriju.");
	Objava o5(nullptr, "");
	Objava o6(nullptr, "");
	o5 = o1;
	o6 = Objava(nullptr, "Mark Zakerberg vas je dodao za prijatelja.");
	std::cout << o1 << endl;
	std::cout << o2 << endl;
	std::cout << o3 << endl;
	std::cout << o4 << endl;
	std::cout << o5 << endl;
	std::cout << o6 << endl; //ispisivace 12 za id jer ce se premestanjem promeniti ID
}

void testKorisnik() {
	std::cout << "************************" << std::endl;
	Korisnik andrija("Andrija");
	Korisnik nikola("Nikola");
	andrija.send(new Objava(nullptr, "Andrija vas je bocnuo."), &nikola);
	andrija.send(new Objava(nullptr, "Mark Zakerberg vas je dodao za prijatelja."), &nikola);
	std::cout << andrija<<endl;
	std::cout << nikola << endl;
	std::cout << "************************" << std::endl;

	cout << +nikola.getNotifications() << endl;

	nikola.getNotifications()();
	nikola.getNotifications()[13]->readIt();

	cout << +nikola.getNotifications() << endl;

	nikola.getNotifications()();
	!nikola.getNotifications();

	cout << +nikola.getNotifications() << endl;

	~nikola.getNotifications();

	cout << +nikola.getNotifications() << endl;
}

int main() {
	testObavestenje();
	testObjava();
	testKorisnik();
	system("pause");
	return 0;
}
