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
	Datum new_date;
	if (production_date.isLeapYear() && production_date["mesec"] == 2 && production_date["dan"] == 29)
		new_date = Datum(1, 3, production_date["godina"] + 2);
	else
		new_date = Datum(production_date["dan"], production_date["mesec"], production_date["godina"] + 2);
	
	if (!(new_date < date))	//new_date = production + 2 years // ako je manje znaci da je proslo 2 godine
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
