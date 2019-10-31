#include "flota.h"



flota::flota(const char c[])
{
	strcpy_s(name, c);
}

int flota::number_of_airplanes()
{
	return airplanes.size();
}

int flota::number_of_max_passengers()
{
	int s = 0;
	for (int i = 0; i < airplanes.size(); ++i)
		s += airplanes[i].get_max_passengers();

	return s;
}

avion flota::biggest_airplane()
{
	int s = 0;
	avion p;
	for (int i = 0; i < airplanes.size(); ++i)
		if (s < airplanes[i].get_max_passengers())
		{
			s = airplanes[i].get_max_passengers();
			p = airplanes[i];
		}

	return p;
}

void flota::add_airplane(const avion a)
{
	airplanes.push_back(a);
}

ostream & operator<<(ostream & out, const flota & f)
{
	cout << f.name << endl;
	for (int i = 0; i < f.airplanes.size(); ++i)
		cout << f.airplanes[i];

	return out;
}
