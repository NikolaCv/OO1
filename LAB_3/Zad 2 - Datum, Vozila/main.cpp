#include "myExceptions.h"
#include "Lista.h"
#include "Vozilo.h"
#include "Automobil.h"

#include <iostream>

using namespace std;

//second set of text examples
/*
void test_Lista() {
	try {
		Lista<int> list;
		list += 3;
		list += 4;
		list += 5;
		std::cout << list << std::endl;
		std::cout << list.getLength() << std::endl;
		std::cout << list.doesCurrentExist() << std::endl;
		//++list;
		//list.getCurrentData();
		//list.removeCurrent();
		//list.next();
		list.moveCurrentAtStart();

		std::cout << list.getCurrentData() << std::endl;
		list.moveCurrent();

		std::cout << list.getCurrentData() << std::endl;
		list.deleteCurrent();
		list.moveCurrentAtStart();
		std::cout << list << std::endl;
		list.deleteCurrent();
		list += 6;
		std::cout << list << std::endl;
	}
	catch (const myExceptions::Exception& e) {
		std::cout << e << std::endl;
	}
}

void test_Datum() {
	try {
		Datum d1(25, 5, 2019);
		Datum d2(14, 5, 2019);
		Datum d3 = d1;
		Datum d4;
		std::cout << d4 << std::endl;
		std::cout << d1 << std::endl;
		std::cout << (d1 < d2) << std::endl;
		std::cout << d1 - d2 << std::endl;
		std::cout << d2["dan"] << "  " << d2["mesec"] << " " << d2["godina"] << std::endl;
	//	std::cout << d4["day"] << "  " << d4["month"] << " " << d4["year"] << std::endl;

	
			//Datum d3(30, -5, -1);
			//d2["asfsd"];
			//Datum d4(0, 1, 3);
			//std::cout << d2 - d1;
	}
	catch (const myExceptions::Exception & e) {
		std::cout << e;
	}
}

void test_automobil() {
	try {
		Automobil audi("Audi A3", Datum(), 250, Automobil::LIMUZINA, 125);
		std::cout << audi << std::endl;
		std::cout << audi.getProductionDate() << std::endl;
		std::cout << audi.getModelName() << std::endl;
		std::cout << audi.getNumberOfPassengers() << std::endl;
		std::cout << audi.getRentPricePerDay(Datum(30, 3, 2024), false) << std::endl;
		std::cout << audi.getRentPricePerDay(Datum(30, 3, 2020), false) << std::endl;
		std::cout << audi.getRentPricePerDay(Datum(30, 3, 2020), true) << std::endl;
		Vozilo* pok = &audi;
		Vozilo* kopija = pok->copy();
		std::cout << *kopija << std::endl;
		std::cout << (kopija == pok) << std::endl;
		delete kopija;
	}
	catch (const myExceptions::Exception & e) {
		std::cout << e;
	}
}

int main() {
	test_Lista();
	test_Datum();
	test_automobil();
	system("pause");
	return 0;
}*/


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

void testDatum()
{
	Datum prvi(5, 1, 2020);
	Datum drugi(29, 2, 2020);
	//cout << prvi - drugi << endl;
	cout << drugi - prvi << endl;

	cout << prvi.isLeapYear() << endl;
	cout << prvi["godina"] << endl;
}

void testAuto()
{
	Automobil auto1("opel", Datum(28,12,2018), 1000, Automobil::LIMUZINA, 500);
	
	cout << auto1 << endl << auto1.getRentPricePerDay(Datum(28, 12, 2020), false) << endl;
	
}

int main()
{
	try
	{
		testLista();
	}
	catch (myExceptions::Exception& p) { cout << p; }

	try
	{
		testDatum();
	}
	catch (myExceptions::Exception& p) { cout << p; }

	try
	{
		testAuto();
	}
	catch (myExceptions::Exception& p) { cout << p; }

	system("pause");
	return 0;
}