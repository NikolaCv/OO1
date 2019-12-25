#include "Automobil.h"

Automobil::Automobil(const string & model, const Datum & production_date, int base_rent_price, TYPE vehicle_type, int wage) :Vozilo(model, production_date, base_rent_price), vehicle_type(vehicle_type), wage(wage)
{
	if (vehicle_type == KUPE)
		num_of_passengers = 2;
	else if (vehicle_type == LIMUZINA)
		num_of_passengers = 5;
}

int Automobil::getNumberOfPassengers() const
{
	return num_of_passengers;
}

int Automobil::getRentPricePerDay(const Datum & date, bool driver_needed)
{
	if (production_date - date < 730)
		base_rent_price *= 1.15;

	if (driver_needed)
	{
		this->driver_needed = true;
		base_rent_price += wage;
	}

	return base_rent_price;
}

string Automobil::toString() const
{
	return (vehicle_type == KUPE) ? "- KUPE" : "- LIMUZINA";
}
