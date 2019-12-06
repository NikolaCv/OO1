#include "Slika.h"


Slika::Slika(int width, int height):height(height),width(width)
{
	mapa = new Piksel**[height];

	for (int i = 0; i < height; ++i)
	{
		mapa[i] = new Piksel*[width];
		for (int j = 0; j < width; ++j)
			mapa[i][j] = new Piksel(0, 0, 0);
	}
}

Slika::Slika(const Slika & s)
{
	kopiraj(s);
}

Slika::Slika(Slika && s)
{
	premesti(s);
}

Slika & Slika::operator=(const Slika & s)
{
	if (this != &s)
	{
		brisi();
		kopiraj(s);
	}

	return *this;
}

Slika & Slika::operator=(Slika && s)
{
	if (this != &s)
	{
		brisi();
		premesti(s);
	}

	return *this;
}

Slika::~Slika()
{
	brisi();
}

int Slika::getWidth() const
{
	return width;
}

int Slika::getHeight() const
{
	return height;
}

Piksel* Slika::operator[](Pozicija& position) const
{
	return mapa[position.getRow()][position.getColumn()];
}

void Slika::postaviPiksel(Pozicija& position, Piksel* p)
{
	if (position.getColumn() > width || position.getRow() > height || position.getColumn() < 0 || position.getRow() < 0)
		exit(1);
	delete mapa[position.getRow()][position.getColumn()];
	mapa[position.getRow()][position.getColumn()] = p;
}

int Slika::getPicSize() const
{
	return height*width*24;
}

void Slika::brisi()
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

void Slika::kopiraj(const Slika & s)
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

void Slika::premesti(Slika & s)
{
	height = s.height;
	width = s.width;

	mapa = s.mapa;

	s.mapa = nullptr;
}

ostream & operator<<(ostream & out, const Slika & s)
{
	out << "Size: " << s.getPicSize() << endl;
	
	for (int i = 0; i < s.height; ++i)
	{
		for (int j = 0; j < s.width; ++j)
		{
			out << *s.mapa[i][j] << '\t';
		}
		out << endl;
	}
		
	return out;
}
