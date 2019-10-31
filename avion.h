#pragma once
#include "pilot.h"
#include <iostream>



class avion
{
public:
	avion(const char n[], int);
	avion();
	bool set_captain(pilot& cap);
	void set_copilot(pilot& cop);
	pilot get_captain();
	pilot get_copilot();
	int get_max_passengers();
	char* get_name();
	friend std::ostream& operator<<(std::ostream &out, const avion& a);
	~avion() = default;
private:
	char name[20];
	pilot* captain;
	pilot* copilot;
	int max_passengers;
};

