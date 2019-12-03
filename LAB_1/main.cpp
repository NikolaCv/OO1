#include "pilot.h"
#include "avion.h"
#include "flota.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

int main()
{
	pilot p1("nikola", 6, true);
	pilot p2("marko", 150, false);

	cout << p1.get_flight_hours() << endl;

	cout << p1.get_flight_info() << endl;

	cout << p1.get_name() << endl;

	p1.change_flight_info(false);

	p1.increase_flight_hours(4);

	cout << p1;

	avion a1("jat", 100);

	a1.set_captain(p1);
	a1.set_copilot(p1);
	p1.change_flight_info(false);
	a1.set_captain(p2);
	a1.set_copilot(p1);

	if(a1.get_captain())
	cout << *a1.get_captain();

	if (a1.get_copilot())
		cout << *a1.get_copilot();


	avion a2("avion2", 150);

	avion a3("avionce3", 250);
	avion a4("najveci avion", 300);

	flota f("moja flota");

	f.add_airplane(&a1);
	f.add_airplane(&a2);
	f.add_airplane(&a3);
	f.add_airplane(&a4);

	cout << *f.biggest_airplane() << endl;
	cout << f.number_of_airplanes() << endl;
	cout << f.number_of_max_passengers() << endl;

	cout << f << endl;
	
	flota f2 = f;

	cout << f2 << f << endl;

	f.add_airplane(&a1);

	cout << f2 << f << endl;

	flota f3 = flota("nova flota 3").add_airplane(&a4).add_airplane(&a2);

	cout << f3;

	system("pause");
	return 0;
}
