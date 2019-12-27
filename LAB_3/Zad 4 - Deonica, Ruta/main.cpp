#include "myExceptions.h"
#include "Lista.h"
#include "Mesto.h"
#include "Deonica.h"
#include "Ruta.h"

#include <iostream>

using namespace std;
//second set of test examples
/*
void test_Lista() {
	try {
		Lista<int> list;
		list += 3;
		list += 4;
		list += 5;
		list += 7;
		list += 8;
		std::cout << list << "******" << std::endl;
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
		std::cout << "******\n" << list << "******" << std::endl;
		list.deleteCurrent();
		list += 6;
		list.moveCurrentAtStart();
		list.moveCurrent();	
		list.moveCurrent();
		Lista<int> kopija(list);
		list.deleteCurrent();
		std::cout << list << "******" << std::endl;
		std::cout << kopija << "******" << std::endl;
		std::cout << kopija.getCurrentData() << std::endl;
	}
	catch (const myExceptions::Exception & e) {
		std::cout << e << std::endl;
	}
}

void test_Mesto() {
	Mesto bg("Beograd", 44.7866, 20.4489);
	Mesto nis("Nis", 43.320902, 21.895759);
	std::cout << bg.getName() << std::endl;
	std::cout << bg.getWidth() << " " << bg.getLength() << std::endl;
	std::cout << bg.getWidth() << " " << bg.getLength() << std::endl;
	std::cout << nis << std::endl;
	std::cout << bg - nis << std::endl;
}

void test_Deonica() {
	Mesto bg("Beograd", 20.457273, 44.787197);
	Mesto nis("Nis", 21.895759, 43.320902);
	Mesto sabac("Sabac", 19.6908, 44.7489);
	Deonica e75(&bg, &nis, Deonica::AUTOPUT);
	Deonica bgsa(&bg, &sabac, Deonica::MAGISTRALNI);
	std::cout << e75 << std::endl;
	std::cout << bgsa << std::endl;
	std::cout << e75(Deonica::TESKO) << std::endl;
	std::cout << e75(Deonica::LAKO) << std::endl;
	std::cout << bgsa(Deonica::TESKO) << std::endl;
}

void test_Ruta() {
	Mesto bg("Beograd", 20.457273, 44.787197);
	Mesto nis("Nis", 21.895759, 43.320902);
	Mesto sabac("Sabac", 19.6908, 44.7489);
	Deonica e75(&bg, &nis, Deonica::AUTOPUT);
	Deonica bgsa(&bg, &sabac, Deonica::MAGISTRALNI);
	Ruta ruta;
	ruta += &e75;
	ruta += &bgsa;
	std::cout << ruta;
	std::cout << ruta(1) << std::endl;
	std::cout << ruta(6.5) << std::endl;
	std::cout << ruta(Deonica::LAKO) << std::endl;
}

int main() {
	test_Lista();
	test_Mesto();
	test_Deonica();
	test_Ruta();
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
	catch (myExceptions::Exception& p) { cout << p; }

	try
	{
		testMesto();
	}
	catch (myExceptions::Exception& p) { cout << p; }

	try
	{
		testDeonica();
	}
	catch (myExceptions::Exception& p) { cout << p; }

	try
	{
		testRuta();
	}
	catch (myExceptions::Exception& p) { cout << p; }

	

	system("pause");
	return 0;
}