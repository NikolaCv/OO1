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
	void brisi();
	void kopiraj(const Slika& s);
	void premesti(Slika& s);

};

#endif