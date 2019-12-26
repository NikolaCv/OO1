#include "myExceptions.h"
#include "Korisnik.h"
#include "Lista.h"
#include "Multimedija.h"
#include "Slika.h"
#include "Evidencija.h"

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
		//testKorisnik();
	}
	catch (myExceptions::BadPassFormatException& p) { cout << p; }
	catch (myExceptions::IncorrectPasswordException& p) { cout << p; }

	try
	{
		//testLista();
	}
	catch (myExceptions::InvalidIndexException& p) { cout << p; }

	try
	{
		testEvidencija();
	}
	catch (myExceptions::UserAlreadyExistsException& p) { cout << p; }
	catch (myExceptions::UserDoesntExistException& p) { cout << p; }
	catch (myExceptions::InvalidIndexException& p) { cout << p; }

	testMultimedija();

	system("pause");
	return 0;
}