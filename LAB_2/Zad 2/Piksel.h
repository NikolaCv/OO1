#ifndef PIKSEL_H
#define PIKSEL_H

#include <iostream>

using namespace std;

class Piksel
{
public:
	Piksel(int red, int green, int blue);
	~Piksel() = default;
	Piksel(const Piksel& piksel) = default;
	Piksel(Piksel&& piksel) = default;
	Piksel& operator=(const Piksel& piksel) = default;
	Piksel& operator=(Piksel&& piksel) = default;
	int getRed() const;
	int getGreen() const;
	int getBlue() const;
	Piksel operator+(const Piksel& p) const;
	bool operator==(const Piksel& p) const;
	bool operator!=(const Piksel& p) const;
	friend ostream& operator<<(ostream& out, const Piksel& piksel);
	Piksel* kopija();
	int aritmetickaSredina() const;
private:
	int r, g, b;
	void kopiraj(const Piksel& p)
	{
		r = p.r;
		g = p.g;
		b = p.b;
	}
};

#endif