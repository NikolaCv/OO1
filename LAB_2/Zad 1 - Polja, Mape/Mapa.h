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
	void brisi()
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				delete map[i][j];
			delete map[i];
		}
		map = nullptr;
	}
	void kopiraj(const Mapa& m)
	{
		n = m.n;
		this->m = m.m;

		map = new Polje**[n];

		for (int i = 0; i < n; ++i)
		{
			map[i] = new Polje*[this->m];
			for (int j = 0; j < this->m; ++j)
				map[i][j] = m.map[i][j]->kopija();
		}
	}
	void premesti(Mapa& m)
	{
		n = m.n;
		this->m = m.m;

		map = m.map;

		m.map = nullptr;
	}
};

#endif