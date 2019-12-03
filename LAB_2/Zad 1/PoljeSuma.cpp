#include "PoljeSuma.h"

PoljeSuma::PoljeSuma(int blockage, int gustina):Polje(blockage),density(gustina)
{
	tag = 'S';
}

string PoljeSuma::toString() const
{
	return to_string(path_blockage) + "_" + tag + "(" + to_string(density) + ")";
}

PoljeSuma * PoljeSuma::kopija() const
{
	return new PoljeSuma(*this);
}

