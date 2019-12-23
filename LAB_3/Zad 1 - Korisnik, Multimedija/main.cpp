#include "myExceptions.h"
#include "Korisnik.h"
#include "Lista.h"

using namespace std;

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

	list += nikola;
	list += andrija;
	list += andrea;
	cout << list.getLength() << endl;

	cout << list[1] << endl;
	list(1);
	cout << list[1] << endl;
}

int main()
{
	try
	{
		//testKorisnik();
	}
	catch (myExceptions::BadPassFormatException& p) { cout << p; }
	catch (myExceptions::IncorrectPasswordException& p) { cout << p; }

	try
	{
		testLista();
	}
	catch (myExceptions::InvalidIndexException& p) { cout << p; }



	system("pause");
	return 0;
}