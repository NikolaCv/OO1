#ifndef PILOT_H
#define PILOT_H
#include <iostream>
#include <string>

class pilot
{
public:
	pilot();
	pilot(std::string c, int, bool);
	pilot(const pilot& p) = delete;
	pilot(pilot&& p) = delete;
	std::string get_name();
	int get_flight_hours();
	bool get_flight_info();
	void increase_flight_hours(int b);
	void change_flight_info(bool b);
	friend std::ostream& operator<<(std::ostream& out, const pilot& p);
	~pilot() = default;
private:
	std::string name;
	int flight_hours;
	bool flight_info;
};

#endif