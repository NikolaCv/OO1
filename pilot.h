#pragma once
#include <iostream>

class pilot
{
public:
	pilot();
	pilot(const char c[], int, bool);
	char* get_name();
	int get_flight_hours();
	bool get_flight_info();
	void increase_flight_hours(int b);
	void change_flight_info(bool b);
	friend std::ostream& operator<<(std::ostream& out, const pilot& p);
	~pilot() = default;
private:
	char name[20];
	int flight_hours;
	bool flight_info;
};

