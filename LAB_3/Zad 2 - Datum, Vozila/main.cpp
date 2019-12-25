#include "myExceptions.h"
#include "Lista.h"
#include "Vozilo.h"
#include "Automobil.h"

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

	list.moveCurrentAtStart();
	//list.deleteCurrent();
	list.moveCurrent();
	//list.moveCurrent();

	cout << list.getCurrentData() <<endl<<endl;

	list.deleteCurrent();

	cout << list << endl;

}

void testAuto()
{
	Automobil auto1("opel", Datum(28,12,2018), 1000, Automobil::LIMUZINA, 500);
	
	cout << auto1 << auto1.getRentPricePerDay(Datum(28, 12, 2018),true);
	
}

int main()
{
	try
	{
		testLista();
	}
	catch (myExceptions::CurrentElementDoesntExist& p) { cout << p; }

	testAuto();



	system("pause");
	return 0;
}