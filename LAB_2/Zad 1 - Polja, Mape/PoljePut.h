#ifndef POLJEPUT_H
#define POLJEPUT_H

#include "Polje.h"
#include <iostream>

using namespace std;


class PoljePut : public Polje
{
public:
	PoljePut(int blockage, int tag);
	PoljePut(const PoljePut&) = default;
	PoljePut(PoljePut&&) = default;
	PoljePut& operator=(const PoljePut& p) = default;
	PoljePut& operator=(PoljePut&& p) = default;
	PoljePut* kopija() const override;
};

#endif