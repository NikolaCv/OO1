#include "myExceptions.h"
#include "Lista.h"
#include "Stajaliste.h"
#include "Gradska_linija.h"
#include "Mreza.h"

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
	//list.moveCurrent();

	cout << list.getCurrentData() << endl << endl;

	list.deleteCurrent();

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

	//delete cvetko1;

	Lista<Stajaliste*> list;
	((((list += ustanicka) += koste1) += mite1) += velizar1) += cvetko1;
	Gradska_linija sedmica("7", list);

	cout << sedmica;

	delete ustanicka;
	delete koste1;
	delete mite1;
	delete velizar1;
	delete cvetko1;
}

void testMreza()
{
	Stajaliste* ustanicka = new Stajaliste(1, "ustanicka", 1);
	Stajaliste* koste1 = new Stajaliste(2, "koste trifkovica", 1);
	Stajaliste* mite1 = new Stajaliste(3, "mite ruzica", 1);
	Stajaliste* velizar1 = new Stajaliste(4, "velizara kosanovica", 1);
	Stajaliste* cvetko1 = new Stajaliste(5, "cvetkova pijaca", 1);

	//delete cvetko1;

	Lista<Stajaliste*> list;
	((((list += ustanicka) += koste1) += mite1) += velizar1) += cvetko1;
	Gradska_linija sedmica("7", list);
	/*Lista<Stajaliste*> list2;
	((list += ustanicka) += mite1) += velizar1;
	Gradska_linija petica("5L", list2);*/

	Mreza beograd;
	//cout << sedmica << endl;
	beograd += sedmica;
	//beograd += petica;

	cout << beograd << endl;

	delete ustanicka;
	delete koste1;
	delete mite1;
	delete velizar1;
	delete cvetko1;
	
}


int main()
{
	try
	{
		//testLista();
	}
	catch (myExceptions::CurrentElementDoesntExist& p) { cout << p; }

	//testStajaliste();

	//testLinija();

	testMreza();

	system("pause");
	return 0;
}