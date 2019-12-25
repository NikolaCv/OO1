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

//TODO: dodavanje liste u gradsku liniju, i onda linije u mrezu

int main()
{
	try
	{
		testLista();
	}
	catch (myExceptions::CurrentElementDoesntExist& p) { cout << p; }

	testStajaliste();

	system("pause");
	return 0;
}