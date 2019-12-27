#include "myExceptions.h"
#include "Korisnik.h"
#include "Lista.h"
#include "Multimedija.h"
#include "Slika.h"
#include "Evidencija.h"

using namespace std;
//second set of test examples
/*
void test_korisnik() {
	try {
		Korisnik k1("andrija", "nikola21");
		Korisnik k2("andrija", "34lolsdfsdfdsfg");
		std::cout << k1.getName() << " " << k1.getPassword() << std::endl;
		std::cout << k2 << std::endl;
		k2.changePassword("34lolsdfsdfdsfg", "12345678o");
		std::cout << (k1 == k2) << " " << k2.getPassword() << std::endl;
	}
	catch (const myExceptions::Exception & e) {
		std::cout << e;
	}
}

void test_Lista() {
	try {
		Lista<int> list;
		list += 2;
		list += 3;
		list += 4;
		std::cout << list.getLength() << " " << list << std::endl;
		std::cout << list[1] << std::endl;
		Lista<int> l2(list);
		list(0);
		std::cout << list.getLength() << " " << list << std::endl;
		std::cout << l2.getLength() << " " << l2 << std::endl;
		l2 = list;
		std::cout << l2.getLength() << " " << l2 << std::endl;
	}
	catch (const myExceptions::Exception & e) {
		std::cout << e << std::endl;
	}
}

void test_Slika() {
	Slika s1("Slika1", 20, 30, 1);
	std::cout << s1 << std::endl;
	Multimedija* m = &s1;
	Multimedija* kopija = m->copy();
	std::cout << *kopija << std::endl;
	std::cout << (kopija == m) << std::endl;
	delete kopija;
}

void test_Evidencija() {
	Evidencija ek;
	std::cout << ek << std::endl;
	try {
		ek += Korisnik("andrija", "nikola123");
		ek += Korisnik("nikola", "andrija123");
		ek += Korisnik("iva", "anrija123");
		//ek += Korisnik("andrija", "asdfdfgf234235");
		std::cout << ek << std::endl;
		std::cout << ek["andrija"] << std::endl;
		ek("andrija");
		std::cout << ek << std::endl;
		//ek("asdf");
		//ek["asd"];
		ek.changePassword("nikola", "andrija123", "dfgfdg2334");
		std::cout << ek["nikola"].getPassword() << std::endl;
	}
	catch (const myExceptions::Exception & e) {
		std::cout << e;
	}
}
int main() {
	test_korisnik();
	test_Lista();
	test_Slika();
	test_Evidencija();
	system("pause");
	return 0;
}
*/

void testKorisnik()
{
	Korisnik nikola("Nikola", "sifra123");
	Korisnik andrija("andrija", "sifra123");
	Korisnik andrea("andrea", "sifra123");
	Korisnik nikola1 = nikola;
	Korisnik andrija1("asdasdasd", "asdasdasd222");
	andrija1 = andrija;
	cout << nikola << endl << andrija << endl << andrea << endl << nikola1 << endl << andrija1 << endl;
	andrea.changePassword("sifra123", "nova1234");
	cout << andrea << endl;
	if (nikola1 == nikola) cout << "da" << endl;
	if (andrija1 != nikola1)cout << "ne" << endl;
}

void testLista()
{
	Lista<Korisnik> list;

	Korisnik nikola("Nikola", "sifra123");
	Korisnik andrija("andrija", "sifra123");
	Korisnik andrea("andrea", "sifra123");

	((list += nikola) += andrija) += andrea;

	cout << list.getLength() << endl;

	cout << list << "----------" << endl;
	list(1);
	cout << list << endl;

	Lista<Korisnik> druga = list;

	cout << list;

	Lista<int> treca(Lista<int>());

	//cout << treca;

	Lista<Korisnik> lista_kor;

	(lista_kor += Korisnik("marko", "sifra1234")) += Korisnik("djina", "sifra1234");
	cout << endl << lista_kor;

	Lista<Korisnik> pok2 = lista_kor;

	cout << pok2;
}

void testEvidencija()
{
	Evidencija evidencija;
	((evidencija += Korisnik("Nikola", "sifra123")) += Korisnik("andrija", "sifra123")) += Korisnik("andrea", "sifra123");
	cout << evidencija;
	evidencija("andrija");
	cout << evidencija;
}

void testMultimedija()
{
	Multimedija* slika = new Slika("moja slika", 10, 10, 1);
	cout << *slika << endl;
}

int main()
{
	try
	{
		testKorisnik();
	}
	catch (myExceptions::Exception& p) { cout << p; }

	try
	{
		testLista();
	}
	catch (myExceptions::Exception& p) { cout << p; }

	try
	{
		testEvidencija();
	}
	catch (myExceptions::Exception& p) { cout << p; }

	try
	{
		testMultimedija();
	}
	catch (myExceptions::Exception& p) { cout << p; }


	system("pause");
	return 0;
}