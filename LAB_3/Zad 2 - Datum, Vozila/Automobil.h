#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

#include "myExceptions.h"
#include "Vozilo.h"
#include "Datum.h"

class Automobil : public Vozilo
{
public:
	enum TYPE { KUPE, LIMUZINA };//zasto mora u public? ne bi trebalo da mora

	Automobil(const string& model, const Datum& production_date, int base_rent_price, enum TYPE vehicle_type, int wage);
	~Automobil() = default;

	int getNumberOfPassengers() const override;
	int getRentPricePerDay(const Datum& date, bool driver_needed) override;
	virtual string toString() const override;

private:
	TYPE vehicle_type;
	int wage;
	int num_of_passengers;
	bool driver_needed = false;
};

#endif