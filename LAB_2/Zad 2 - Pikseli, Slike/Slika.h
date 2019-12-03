#ifndef SLIKA_H
#define SLIKA_H

#include "Piksel.h"
#include "Pozicija.h"
#include <iostream>

using namespace std;

class Slika
{
public:
	Slika(int width, int height);
	Slika(const Slika& slika);
	Slika(Slika&& slika);
	Slika& operator=(const Slika& slika);
	Slika& operator=(Slika&& slika);
	~Slika();
	int getWidth() const;
	int getHeight() const;
	Piksel* operator[](Pozicija& position) const;
	virtual void postaviPiksel(Pozicija& position, Piksel* piksel);
	int getPicSize() const;
	friend ostream& operator<<(ostream& out, const Slika& slika);

protected:
	int width, height;
	Piksel*** mapa;
	void brisi()
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				delete mapa[i][j];
			}
			delete[] mapa[i];
		}
		mapa = nullptr;
	}
	void kopiraj(const Slika& s)
	{
		height = s.height;
		width = s.width;

		mapa = new Piksel**[height];

		for (int i = 0; i < height; ++i)
		{
			mapa[i] = new Piksel*[width];
			for (int j = 0; j < width; ++j)
				mapa[i][j] = s.mapa[i][j]->kopija();
		}
	}
	void premesti(Slika& s)
	{
		height = s.height;
		width = s.width;

		mapa = s.mapa;

		s.mapa = nullptr;
	}

};

#endif