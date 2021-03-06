#include "Vozilo.h"

Vozilo::Vozilo(const string & model, const Datum & production_date, int base_rent_price):model_name(model),production_date(production_date),base_rent_price(base_rent_price)
{
}

ostream & operator<<(ostream & out, const Vozilo & vehicle)
{
	return out << vehicle.model_name << "-" << vehicle.getNumberOfPassengers() << "-" << vehicle.production_date << vehicle.toString();
}

int Vozilo::getBaseRentPrice() const
{
	return base_rent_price;
}

string Vozilo::getModelName() const
{
	return model_name;
}

const Datum & Vozilo::getProductionDate() const
{
	return production_date;
}
