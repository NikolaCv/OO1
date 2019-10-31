#pragma once
#include <vector>
#include "avion.h"
#include <iostream>

using namespace std;

class flota
{
public:
	flota(const char c[]);
	int number_of_airplanes();
	int number_of_max_passengers();
	avion biggest_airplane();
	void add_airplane(const avion a);
	friend ostream& operator<<(ostream& out, const flota& f);
	~flota() = default;
private:
	char name[20];
	vector<avion> airplanes;
};

