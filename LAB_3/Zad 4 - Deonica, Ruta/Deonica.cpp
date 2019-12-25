#include "Deonica.h"

Deonica::Deonica(Mesto * start_place, Mesto * end_place, KATEGORIJA_PUTA category):start_place(start_place),end_place(end_place),category(category)
{
}


Deonica::~Deonica()
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

double Deonica::operator()(KATEGORIJA_VOZILA category)
{
	if (category == LAKO) return ~(*this) * 12;
	if(category == TESKO) return ~(*this) * 22;
}

ostream & operator<<(ostream & out, const Deonica & section)
{
	return out << "[" << *section.start_place << " -> " << *section.end_place << "]" << ~section;
}
