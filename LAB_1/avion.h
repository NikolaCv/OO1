#ifndef AVION_H
#define AVION_H
#include "pilot.h"
#include <iostream>
#include <string>


class avion
{
public:
	avion();
	avion(std::string n, int);
	avion(const avion& p) = delete;
	avion(const avion&& p) = delete;
	bool set_captain(pilot& cap);
	bool set_copilot(pilot& cop);
	pilot* get_captain();
	pilot* get_copilot();
	int get_max_passengers();
	std::string get_name();
	friend std::ostream& operator<<(std::ostream &out, const avion& a);
	~avion() = default;
private:
	std::string name;
	pilot* captain;
	pilot* copilot;
	int max_passengers;
};

#endif