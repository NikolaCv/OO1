#include "myExceptions.h"
#include "Lista.h"

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


int main()
{
	try
	{
		testLista();
	}
	catch (myExceptions::CurrentElementDoesntExist& p) { cout << p; }

	system("pause");
	return 0;
}