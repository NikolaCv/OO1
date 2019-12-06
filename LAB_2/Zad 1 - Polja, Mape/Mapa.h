#ifndef MAPA_H
#define MAPA_H

#include "Polje.h"
#include <iostream>

using namespace std;

class Mapa
{
public:
	Mapa(int height, int width);
	Mapa(const Mapa&);
	Mapa(Mapa&&);
	~Mapa();
	Mapa& operator=(const Mapa& mapa);
	Mapa& operator=(Mapa&& mapa);
	Mapa& zameniPolje(int red, int kol, Polje* polje);
	Mapa& operator+=(int a);
	Mapa& operator-=(int a);
	friend ostream& operator<<(ostream& out, const Mapa& mapa);
private:
	Polje*** map;
	int n, m;
	void brisi();
	void kopiraj(const Mapa& m);
	void premesti(Mapa& m);
};

#endif