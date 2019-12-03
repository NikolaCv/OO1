#ifndef POLJESUMA_H
#define POLJESUMA_H

#include "Polje.h"

class PoljeSuma : public Polje
{
public:
	PoljeSuma(int blockage, int gustina);
	PoljeSuma(const PoljeSuma&) = default;
	PoljeSuma(PoljeSuma&&) = default;
	PoljeSuma& operator=(const PoljeSuma& p) = default;
	PoljeSuma& operator=(PoljeSuma&& p) = default;
	string toString() const override;
	PoljeSuma* kopija() const override;
private:
	int density;
};

#endif