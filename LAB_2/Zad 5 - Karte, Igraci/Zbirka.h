#ifndef ZBIRKA_H
#define ZBIRKA_H

#include "Karta.h"
#include "Carobnjak.h"

class Zbirka
{
public:
	struct Node
	{
		Karta* card;
		Node* next;
		Node(Karta * n) :next(nullptr)//konstruktor za strukturu(listu)
		{
			card = n;
		}
	};
	Zbirka();
	Zbirka(const Zbirka& collection);
	Zbirka(Zbirka&& collection);
	Zbirka& operator=(const Zbirka& collection);
	Zbirka& operator=(Zbirka&& collection);
	~Zbirka();
	int getLength() const;
	Zbirka& operator+=(Karta * card);
	Karta* operator[](int index) const;
	Karta* operator[](unsigned id) const;
	void operator()(int index);
	void operator()(unsigned id);
	void operator~();
	friend ostream& operator<<(ostream & out, const Zbirka& collection);

private:
	Node* prvi, *posl;
	int len = 0;
	void kopiraj(const Zbirka& collection);	//kada kopiramo pravimo novu kartu sa novim ID,
											//i istim atributima, jer karta ne moze obicno da se kopira
	void premesti(Zbirka& collection);		//ovde samo premestamo pokazivace
	void brisi();
};

#endif