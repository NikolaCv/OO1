#include "myExceptions.h"
#include "Lista.h"
#include "Stajaliste.h"
#include "Gradska_linija.h"
#include "Mreza.h"

#include <iostream>
#include <string>

using namespace std;

//another set of testing examples
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
	catch (myExceptions::Exception & e) {
		std::cout << e << std::endl;
	}
}

void test_Stajaliste() {
	Stajaliste s1(558, "Juzni Bulevar", 1);
	Stajaliste s2(557, "Juzni Bulevar", 1);
	Stajaliste s3(558, "Juzsdfni Bulevar", 134);
	std::cout << s1 << std::endl;
	std::cout << s1.getName() << std::endl;
	std::cout << s1.getZone() << std::endl;
	std::cout << (s1 == s2) << " " << (s1 == s3) << std::endl;
}

void test_GradskaLinija() {
	Stajaliste s1(551, "Juzni Bulevar", 1);
	Stajaliste s2(552, "Kalenic Pijaca", 1);
	Stajaliste s3(553, "Tehnicki Fakulteti", 1);
	Stajaliste s4(554, "Pravni Fakultet", 1);
	Stajaliste s5(555, "Glavna Posta", 1);
	Stajaliste s6(556, "Trg Republike", 1);
	Stajaliste* s7 = new Stajaliste(1, "Dinamik", 1);
	Lista<Stajaliste*> lista1, lista2;
	lista1 += &s1;
	lista1 += &s2;
	lista1 += &s3;
	lista1 += &s4;
	lista2 += &s5;
	lista2 += &s2;
	lista2 += &s6;
	lista2 += &s3;
	lista1 += s7;
	lista2 += s7;
	Gradska_linija g26("26", lista1);
	Gradska_linija* g24 = new Gradska_linija("24", lista2);
	std::cout << (g26 & *g24) << std::endl;
	std::cout << g26;
	std::cout << *g24 << "*************\n";
	delete s7;
	std::cout << g26;
	std::cout << *g24 << "*************\n";
	delete g24;


}

void test_mreza() {
	Stajaliste s1(551, "Juzni Bulevar", 1);
	Stajaliste s2(552, "Kalenic Pijaca", 1);
	Stajaliste s3(553, "Tehnicki Fakulteti", 1);
	Stajaliste s4(554, "Pravni Fakultet", 1);
	Stajaliste s5(555, "Glavna Posta", 1);
	Stajaliste s6(556, "Trg Republike", 1);
	Lista<Stajaliste*> lista1, lista2;
	lista1 += &s1;
	lista1 += &s2;
	lista1 += &s3;
	lista1 += &s4;
	lista2 += &s5;
	lista2 += &s2;
	lista2 += &s6;
	lista2 += &s3;
	Gradska_linija g26("26", lista1);
	Gradska_linija g24("24", lista2);
	Mreza m;
	m += g26;
	m += g24;
	std::cout << m << std::endl;
}

int main() {
	test_Lista();
	test_Stajaliste();
	test_GradskaLinija();
	test_mreza();
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

	cout <<"ruga"<< list2 << endl;

	Lista<int> list3;
	//cout <<"2 current data" <<list2.getCurrentData() << endl;

	list2.moveCurrentAtStart();
	list2.moveCurrent();
	list2.deleteCurrent();
	list3 = list2;

	cout <<"treca"<< list3 << endl;

	list.moveCurrentAtStart();
	//list.deleteCurrent();
	list.moveCurrent();
	list.moveCurrent();

	cout << list.getCurrentData() << endl << endl;

	list.deleteCurrent();
	//list.deleteCurrent();
	//list.deleteCurrent();


	cout << list << endl;

}

void testStajaliste()
{
	Stajaliste ustanicka(1, "ustanicka", 1);
	Stajaliste koste1(2, "koste trifkovica", 1);
	Stajaliste mite1(3, "mite ruzica", 1);
	Stajaliste velizar1(4, "velizara kosanovica", 1);
	Stajaliste cvetko1(5, "cvetkova pijaca", 1);
	cout << ustanicka << endl;

	Stajaliste novo(1, "ustan", 1);
	if (novo == ustanicka)
		cout << "true"<<endl;
}

void testLinija()
{
	Stajaliste* ustanicka = new Stajaliste(1, "ustanicka", 1);
	Stajaliste* koste1 = new Stajaliste(2, "koste trifkovica", 1);
	Stajaliste* mite1 = new Stajaliste(3, "mite ruzica", 1);
	Stajaliste* velizar1 = new Stajaliste(4, "velizara kosanovica", 1);
	Stajaliste* cvetko1 = new Stajaliste(5, "cvetkova pijaca", 1);

	Lista<Stajaliste*> list;
	((((list += ustanicka) += koste1) += mite1) += velizar1) += cvetko1;
	Gradska_linija sedmica("7", list);

	cout << sedmica;

	delete mite1;
	cout << sedmica << endl;


	delete ustanicka;
	delete koste1;
	delete velizar1;
	delete cvetko1;
}

void testMreza()
{
	Stajaliste ustanicka = Stajaliste(1, "ustanicka", 1);
	Stajaliste* koste1 = new Stajaliste(2, "koste trifkovica", 1);
	Stajaliste* mite1 = new Stajaliste(3, "mite ruzica", 1);
	Stajaliste* velizar1 = new Stajaliste(4, "velizara kosanovica", 1);
	Stajaliste* cvetko1 = new Stajaliste(5, "cvetkova pijaca", 1);

	Lista<Stajaliste*> list;
	((((list += &ustanicka) += koste1) += mite1) += velizar1) += cvetko1;
	
	Gradska_linija sedmica("7", list);
	Lista<Stajaliste*> list2;
	((list2 += &ustanicka) += mite1) += velizar1;
	Gradska_linija petica("5L", list2);

	Mreza beograd;
	//cout << sedmica << endl;
	beograd += sedmica;
	beograd += petica;

	cout << beograd << endl;

	cout << "Stajaliste Ustanicka:" << endl;

	for (ustanicka.getLines().moveCurrentAtStart(); ustanicka.getLines().doesCurrentExist(); ustanicka.getLines().moveCurrent()) {
		std::cout << *ustanicka.getLines().getCurrentData() << std::endl;
	}


	delete koste1;
	delete mite1;
	delete velizar1;
	delete cvetko1;
	
	cout << sedmica << endl;
	cout << "ispis" << endl;
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
		testStajaliste();
	}
	catch (myExceptions::Exception& p) { cout << p; }


	try
	{
		testLinija();
	}
	catch (myExceptions::Exception& p) { cout << p; }

	try
	{
		testMreza();
	}
	catch (myExceptions::Exception& p) { cout << p; }


	system("pause");
	return 0;
}