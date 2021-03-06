#include "pilot.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

pilot::pilot()
{
	name = '\0';
	flight_hours = 0;
	flight_info = false;
}

pilot::pilot(string c, int f, bool b)
{
	name = c;
	flight_hours = f;
	flight_info = b;
}

string pilot::get_name()
{
	return name;
}

int pilot::get_flight_hours()
{
	return flight_hours;
}

bool pilot::get_flight_info()
{
	return flight_info;
}

void pilot::increase_flight_hours(int b)
{
	flight_hours += b;
}

void pilot::change_flight_info(bool b)
{
	flight_info = b;
}

ostream & operator<<(ostream & out, const pilot & p)
{
	cout << p.name << " (" << p.flight_hours << ") - ";
	if(p.flight_info)
		cout << "L" << endl;
	else
		cout << "N" << endl;
	return out;
}
