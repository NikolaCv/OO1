#ifndef ZBIRKA_H
#define ZBIRKA_H

#include "Karta.h"

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
	//kopiranje i premestanje???
	~Zbirka();
	Zbirka& operator+=(Karta * card);
	int getLength() const;
	Karta* operator[](int index);
	Karta* operator[](unsigned id);
	void operator()(int index);
	void operator()(unsigned id);
	void operator~();
	friend ostream& operator<<(ostream & out, const Zbirka collection);

private:
	Node* prvi, *posl;
	int len = 0;

	void brisi()
	{
		while (prvi)
		{
			Node *tek = prvi;
			prvi = prvi->next;
			delete tek;
		}
		posl = nullptr;
		len = 0;
	}
};

#endif