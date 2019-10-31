#include "pilot.h"
#include "avion.h"
#include "flota.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

int main()
{
	pilot p1("nikola\0", 6, true);

	cout << p1.get_flight_hours() << endl;

	cout << p1.get_flight_info() << endl;

	cout << p1.get_name() << endl;

	p1.change_flight_info(false);

	p1.increase_flight_hours(4);

	cout << p1;

	avion a1("jat\0", 100);

	a1.set_captain(p1);
	a1.set_copilot(p1);

	cout << a1.get_captain();

	avion a2("avion2\0", 150);

	avion a3("avionce3\0", 250);
	avion a4("najveci avion\0", 300);

	flota f("moja flota\0");

	f.add_airplane(a1);
	f.add_airplane(a2);
	f.add_airplane(a3);
	f.add_airplane(a4);

	cout << f.biggest_airplane() << endl;
	cout << f.number_of_airplanes() << endl;
	cout << f.number_of_max_passengers() << endl;

	cout << f;


	system("pause");
	return 0;
}
