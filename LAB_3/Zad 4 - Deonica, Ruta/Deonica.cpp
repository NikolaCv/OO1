#include "Deonica.h"

Deonica::Deonica(Mesto * start_place, Mesto * end_place, KATEGORIJA_PUTA category):start_place(start_place),end_place(end_place),category(category)
{
}

Mesto * Deonica::getStartPlace() const
{
	return start_place;
}

Mesto * Deonica::getEndPlace() const
{
	return end_place;
}

Deonica::KATEGORIJA_PUTA Deonica::getCategory() const
{
	return category;
}

double Deonica::operator~() const
{
	return *start_place - *end_place;
}

double Deonica::operator()(KATEGORIJA_VOZILA category_vehicle)
{
	if (category == AUTOPUT)
	{
		if (category_vehicle == LAKO) return ~(*this) * 12;
		if (category_vehicle == TESKO) return ~(*this) * 22;
	}
	else return 0;
}

ostream & operator<<(ostream & out, const Deonica & section)
{
	return out << "[" << *section.start_place << " -> " << *section.end_place << "]" << " - " << ~section << "km";
}
