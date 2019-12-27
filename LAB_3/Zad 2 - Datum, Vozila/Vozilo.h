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

	int getBaseRentPrice() const;
	string getModelName() const;
	const Datum& getProductionDate() const;

	virtual int getNumberOfPassengers() const = 0;
	virtual int getRentPricePerDay(const Datum& date, bool driver_needed) = 0;
	virtual string toString() const = 0;
	friend ostream& operator<<(ostream& out, const Vozilo& vehicle);
	virtual Vozilo* copy() const = 0;

protected:
	int base_rent_price;
	Datum production_date;
	string model_name;

};

#endif