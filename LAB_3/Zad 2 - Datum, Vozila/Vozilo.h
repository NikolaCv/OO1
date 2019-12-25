#ifndef VOZILO_H
#define VOZILO_H

#include "myExceptions.h"
#include "Datum.h"
#include <iostream>

using namespace std;

class Vozilo
{
public:
	Vozilo(const string& model, const Datum& production_date, int base_rent_price);
	Vozilo(const Vozilo& vehicle) = delete;
	Vozilo(Vozilo&& vehicle) = delete;
	Vozilo& operator=(const Vozilo& vehicle) = delete;
	Vozilo& operator=(Vozilo&& vehicle) = delete;
	~Vozilo() = default;

	virtual int getNumberOfPassengers() const = 0;
	virtual int getRentPricePerDay(const Datum& date, bool driver_needed) = 0;
	virtual string toString() const = 0;
	friend ostream& operator<<(ostream& out, const Vozilo& vehicle);

protected:
	int base_rent_price;
	Datum production_date;

private:
	string model_name;

};

#endif