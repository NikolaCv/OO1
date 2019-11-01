#ifndef FLOTA_H
#define FLOTA_H
#include <vector>
#include "avion.h"
#include <iostream>
#include <string>

using namespace std;

class flota
{
public:
	flota();
	flota(std::string c);
	flota(const flota& f) = default;
	flota(flota&& f) = default;
	int number_of_airplanes();
	int number_of_max_passengers();
	string get_name();
	avion* biggest_airplane();
	flota& add_airplane(avion* a);
	friend ostream& operator<<(ostream& out, const flota& f);
	~flota() = default;
private:
	std::string name;
	vector<avion*> airplanes;
};

#endif