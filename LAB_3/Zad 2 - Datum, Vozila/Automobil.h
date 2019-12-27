#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

#include "myExceptions.h"
#include "Vozilo.h"
#include "Datum.h"

class Automobil : public Vozilo
{
public:
	enum TYPE { KUPE, LIMUZINA };

	Automobil(const string& model, const Datum& production_date, int base_rent_price, enum TYPE vehicle_type, int wage);
	~Automobil() = default;

	int getNumberOfPassengers() const override;
	int getRentPricePerDay(const Datum& date, bool driver_needed) override;
	string toString() const override;
	Automobil* copy() const override;
	TYPE getVehicleType() const;
	int getWage() const;

private:
	TYPE vehicle_type;
	int wage;
	int num_of_passengers;

};

#endif