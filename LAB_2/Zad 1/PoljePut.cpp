#include "PoljePut.h"


PoljePut::PoljePut(int a, int c):Polje(a)
{
	tag = c;
	if (tag != 'Z' && tag != 'K')
		tag = 'Z';
}

PoljePut * PoljePut::kopija() const
{
	return new PoljePut(*this);
}
