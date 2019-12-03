#include <iostream>
#include "Polje.h"
#include "PoljePut.h"
#include "PoljeSuma.h"
#include "Mapa.h"

using namespace std;


int main()
{
	Polje* putZ = new PoljePut(250, 'Z');
	Polje* putK = new PoljePut(150, 'K');
	PoljeSuma* suma = new PoljeSuma(500, 600);

	Mapa mapa(2, 2);

	cout << mapa <<endl;

	mapa.zameniPolje(0, 0, putZ);
	mapa.zameniPolje(0, 1, putK);
	mapa.zameniPolje(1, 1, suma);

	cout << mapa << endl;

	Mapa mapa2 = mapa;


	PoljePut* novopolje = new PoljePut(990, 'K');

	mapa2.zameniPolje(0, 0, novopolje);

	cout << mapa2 << endl;

	mapa2 += 50;

	cout << mapa2 << endl;
	
	system("pause");
	return 0;
}