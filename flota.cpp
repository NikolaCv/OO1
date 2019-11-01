#include "flota.h"
#include <string>


flota::flota()
{
	name = '\0';
}

flota::flota(std::string c)
{
	name = c;
}

int flota::number_of_airplanes()
{
	return airplanes.size();
}

int flota::number_of_max_passengers()
{
	int s = 0;
	for (int i = 0; i < airplanes.size(); ++i)
		s += airplanes[i]->get_max_passengers();

	return s;
}

string flota::get_name()
{
	return name;
}

avion* flota::biggest_airplane()
{
	int s = 0;
	avion* p = nullptr;
	for (int i = 0; i < airplanes.size(); ++i)
		if (s < airplanes[i]->get_max_passengers())
		{
			s = airplanes[i]->get_max_passengers();
			p = airplanes[i];
		}

	return p;
}

flota& flota::add_airplane(avion* a)
{
	airplanes.push_back(a);
	return *this;
}

ostream & operator<<(ostream & out, const flota & f)
{
	cout << f.name << endl;
	for (int i = 0; i < f.airplanes.size(); ++i)
		cout << *f.airplanes[i];

	return out;
}
