#include "Mapa.h"

Mapa::Mapa(int n = 0, int m = 0) : n(n), m(m), map(nullptr)
{
	map = new Polje * *[n];
	for (int i = 0; i < n; ++i)
	{
		map[i] = new Polje *[m];
		for (int j = 0; j < m; ++j)
			map[i][j] = new Polje(100);
	}

}

Mapa::Mapa(const Mapa &m)
{
	kopiraj(m);
}

Mapa::Mapa(Mapa && m)
{
	premesti(m);
}

Mapa::~Mapa()
{
	brisi();
}

Mapa & Mapa::operator=(const Mapa & p)
{
	if (this != &p)
	{
		brisi();
		kopiraj(p);
	}

	return *this;
}

Mapa & Mapa::operator=(Mapa && p)
{
	if (this != &p)
	{
		brisi();
		premesti(p);
	}

	return *this;
}

Mapa& Mapa::zameniPolje(int red, int kol, Polje* p)
{
	delete map[red][kol];
	map[red][kol] = p;

	return *this;
}

Mapa& Mapa::operator+=(int a)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			*map[i][j] += a;
		}

	return *this;
}

Mapa& Mapa::operator-=(int a)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			*map[i][j] += a;
		}

	return *this;
}

void Mapa::brisi()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			delete map[i][j];
		delete map[i];
	}
	map = nullptr;
}

void Mapa::kopiraj(const Mapa & m)
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
void Mapa::premesti(Mapa & m)
{
	n = m.n;
	this->m = m.m;

	map = m.map;

	m.map = nullptr;
}

ostream & operator<<(ostream & out, const Mapa & m)
{
	for (int i = 0; i < m.n; ++i)
	{
		for (int j = 0; j < m.m; ++j)
			out << *m.map[i][j] << "\t";
		out << endl;
	}
			
	return out;
}
