#include "avion.h"
#include <iostream>
#include <string>

using namespace std;

avion::avion()
{
	name = '\0';
	max_passengers = 0;
	captain = nullptr;
	copilot = nullptr;
}

avion::avion(string n, int b)
{
	name = n;
	max_passengers = b;
	captain = nullptr;
	copilot = nullptr;
}

bool avion::set_captain(pilot & cap)
{
	if (!cap.get_flight_info() && cap.get_flight_hours() >= 100)
	{
		captain = &cap;
		cap.change_flight_info(true);
		return true;
	}

	std::cout << "Odabrani pilot nema 100 sati letenja ili je u letu." << std::endl;

	return false;
}

bool avion::set_copilot(pilot & cop)
{
	if (cop.get_flight_info())
	{
		std::cout << "Odabrani kopilot je u letu." << std::endl;
		return false;
	}

	copilot = &cop;
	cop.change_flight_info(true);
	return true;
}

pilot* avion::get_captain()
{
		return captain;
}

pilot* avion::get_copilot()
{
	return copilot;
}

int avion::get_max_passengers()
{
	return max_passengers;
}

string avion::get_name()
{
	return name;
}

std::ostream & operator<<(std::ostream & out, const avion & a)
{
	cout << "AVION: " << a.name << " - " << a.max_passengers << endl;

	return out;
}
