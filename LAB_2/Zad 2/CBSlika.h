#ifndef CBSLIKA_H
#define CBSLIKA_H
#include "Slika.h"


class CBSlika : public Slika
{
public:
	CBSlika(int height, int width);
	CBSlika(const CBSlika& s);
	CBSlika(CBSlika&& s);
	CBSlika(const Slika& s);
	CBSlika& operator=(const Slika& s);
	CBSlika& operator=(const CBSlika& s);
	CBSlika& operator=(CBSlika&& s);
	void postaviPiksel(Pozicija& position, Piksel* p) override;

};

#endif