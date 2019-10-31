#include "avion.h"
#include <iostream>

using namespace std;

avion::avion(const char n[], int b)
{
	strcpy_s(name, n);
	max_passengers = b;
	captain = nullptr;
	copilot = nullptr;
}

avion::avion()
{
	name[20] = '\0';
	max_passengers = 0;
}

bool avion::set_captain(pilot & cap)
{
	if (cap.get_flight_hours() >= 100)
	{
		captain = &cap;
		cap.change_flight_info(true);
		return true;
	}

	std::cout << "Odabrani pilot nema 100 sati letenja." << std::endl;

	return false;
}

void avion::set_copilot(pilot & cop)
{
	copilot = &cop;
	cop.change_flight_info(true);
}

pilot avion::get_captain()
{
	if (captain)
		return *captain;
	else
		return pilot("Ne postoji kapetan.", 0, 0);
}

pilot avion::get_copilot()
{
	return *copilot;
}

int avion::get_max_passengers()
{
	return max_passengers;
}

char * avion::get_name()
{
	return name;
}

std::ostream & operator<<(std::ostream & out, const avion & a)
{
	cout << "AVION: " << a.name << " - " << a.max_passengers << endl;

	return out;
}
