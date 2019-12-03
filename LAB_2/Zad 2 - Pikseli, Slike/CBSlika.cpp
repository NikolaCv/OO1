#include "CBSlika.h"

CBSlika::CBSlika(int height, int width):Slika(height,width)
{
}

CBSlika::CBSlika(const CBSlika & s):Slika(s)
{
}

CBSlika::CBSlika(CBSlika && s):Slika(s)
{
}

CBSlika::CBSlika(const Slika & s):Slika(s)
{
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
		{
			delete mapa[i][j];
			Pozicija poz(i, j);
			int ind = (s[poz]->aritmetickaSredina()) >= 127 ? 255 : 0;
			mapa[i][j] = new Piksel(ind, ind, ind);
		}
}

CBSlika & CBSlika::operator=(const Slika & s)
{
	brisi();
	height = s.getHeight();
	width = s.getWidth();

	mapa = new Piksel**[height];

	for (int i = 0; i < height; ++i)
	{
		mapa[i] = new Piksel*[width];

		for (int j = 0; j < width; ++j)
		{
			Pozicija poz(i, j);
			int ind = (s[poz]->aritmetickaSredina()) >= 127 ? 255 : 0;
			mapa[i][j] = new Piksel(ind, ind, ind);
		}
	}

	return *this;
}

CBSlika & CBSlika::operator=(const CBSlika & s)
{
	if (this != &s)
	{
		brisi();
		kopiraj(s);
	}

	return *this;
}

CBSlika & CBSlika::operator=(CBSlika && s)
{
	if (this != &s)
	{
		brisi();
		premesti(s);
	}

	return *this;
}

void CBSlika::postaviPiksel(Pozicija & position, Piksel * p)
{
	if (position.getColumn() > width || position.getRow() > height || position.getColumn() < 0 || position.getRow() < 0)
		exit(1);
	delete mapa[position.getRow()][position.getColumn()];
	int ind = (p->aritmetickaSredina()) >= 127 ? 255 : 0;
	delete p;
	mapa[position.getRow()][position.getColumn()] = new Piksel(ind, ind, ind);
}
