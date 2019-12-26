#include "myExceptions.h"
#include "Lista.h"
#include "Mesto.h"
#include "Deonica.h"
#include "Ruta.h"

#include <iostream>

using namespace std;

void testLista()
{
	Lista<int> list;
	list += 1;
	list += 2;
	list += 3;
	cout << list.doesCurrentExist() << endl << endl;
	//list.getCurrentData();
	//list.deleteCurrent();


	cout << list << endl;

	Lista<int> list2 = list;

	cout << "ruga" << list2 << endl;

	Lista<int> list3;
	//cout <<"2 current data" <<list2.getCurrentData() << endl;

	list2.moveCurrentAtStart();
	list2.moveCurrent();
	list2.deleteCurrent();
	list3 = list2;

	cout << "treca" << list3 << endl;

	list.moveCurrentAtStart();
	//list.deleteCurrent();
	list.moveCurrent();
	//list.moveCurrent();

	cout << list.getCurrentData() << endl << endl;

	list.deleteCurrent();

	cout << list << endl;

}

void testMesto()
{
	Mesto beograd("beograd", 44.7866, 20.4489);
	Mesto pariz("pariz", 48.8566, 2.3522);

	cout << beograd << endl << pariz << endl;

	cout << beograd - pariz << endl;//1,446.29
}

void testDeonica()
{
	Mesto* beograd = new Mesto("beograd", 44.7866, 20.4489);
	Mesto* pariz = new Mesto("pariz", 48.8566, 2.3522);

	Deonica magistrala(beograd,pariz,Deonica::MAGISTRALNI);

	cout << magistrala(Deonica::LAKO) << endl;
	cout << magistrala << endl;
	cout << ~magistrala << endl;

	delete beograd;
	delete pariz;
}

void testRuta()
{
	Mesto* beograd = new Mesto("beograd", 44.7866, 20.4489);
	Mesto* pariz = new Mesto("pariz", 48.8566, 2.3522);
	Mesto* nis = new Mesto("nis", 43.3209, 21.8958);

	Deonica* magistrala = new Deonica(beograd, pariz, Deonica::AUTOPUT);
	Deonica* autoput = new Deonica(beograd, nis, Deonica::MAGISTRALNI);

	Ruta ruta1;

	ruta1 += magistrala;
	ruta1 += autoput;

	cout << ruta1 << endl;

	cout << ruta1(1) << endl;
	cout<< ruta1(Deonica::LAKO) << endl;

	delete beograd;
	delete pariz;
	delete magistrala;
	delete autoput;
}

int main()
{
	try
	{
		testLista();
	}
	catch (myExceptions::CurrentElementDoesntExist& p) { cout << p; }

	testMesto();

	testDeonica();

	try
	{
		testRuta();
	}
	catch (myExceptions::CurrentElementDoesntExist& p) { cout << p; }

	

	system("pause");
	return 0;
}