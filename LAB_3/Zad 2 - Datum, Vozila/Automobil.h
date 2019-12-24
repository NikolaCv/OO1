#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

#include "myExceptions.h"
#include "Vozilo.h"
#include "Datum.h"

class Automobil : public Vozilo
{
public:
	Automobil(const string& model, const Datum& production_date, int base_rent_price, enum type vehicle_type, int wage);
	~Automobil() = default;

	int getNumberOfPassengers() const override;
	int getRentPricePerDay(const Datum& date, bool driver_needed) const override;
	virtual string toString() const override;

private:
	enum type{KUPE,LIMUZINA};
	type vehicle_type;
	int wage;
	int num_of_passengers;
	Automobil(Automobil::type vehicle_type, int wage);
};

#endif