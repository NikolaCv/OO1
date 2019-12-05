#include "Zbirka.h"



Zbirka::Zbirka():prvi(nullptr),posl(nullptr)
{
}

Zbirka & Zbirka::operator+=(Karta * card)
{
	Node* novi = new Node(card);
	if (prvi == nullptr)
	{
		prvi = novi;
		posl = novi;
	}

	else
	{
		novi->next = prvi;
		prvi = novi;
	}


	len++;

	return *this;
	return *this;
}

int Zbirka::getLength() const
{
	return len;
}

Karta * Zbirka::operator[](int index)
{
	Node* tek = prvi;
	int ind = 0;
	while (tek)
	{
		if (ind == index)
			break;
		tek = tek->next;
		ind++;
	}

	if (tek == nullptr)
		return nullptr;

	return tek->card;

}

Karta * Zbirka::operator[](unsigned id)
{
	Node* tek = prvi;
	int ind = 0;
	while (tek)
	{
		if (tek->card->getID() == id)
			break;
		tek = tek->next;
	}

	if (tek == nullptr)
		return nullptr;

	return tek->card;
}

void Zbirka::operator()(int index)
{
	Node* tek, *pret = nullptr;
	tek = prvi;
	int ind = 0;
	while (tek)
	{
		if (ind == index)
		{
			if (pret == nullptr)
			{
				prvi = tek->next;
				delete tek;
				break;
			}
			else
			{
				pret->next = tek->next;
				delete tek;
				if (pret->next == nullptr)
				{
					posl = pret;
				}
				break;
			}
		}
		tek = tek->next;
		ind++;
	}

}

void Zbirka::operator()(unsigned id)
{
	Node* tek, *pret = nullptr;
	tek = prvi;
	while (tek)
	{
		if (tek->card->getID() == id)
		{
			if (pret == nullptr)
			{
				prvi = tek->next;
				delete tek;
				break;
			}
			else
			{
				pret->next = tek->next;
				delete tek;
				if (pret->next == nullptr)
				{
					posl = pret;
				}
				break;
			}
		}
		tek = tek->next;
	}
}

void Zbirka::operator~()
{
	int ind = rand() % len;
	(*this)(ind);
}


Zbirka::~Zbirka()
{
	brisi();
}

ostream & operator<<(ostream & out, const Zbirka collection)
{
	out << "ZBIRKA:" << endl;
	
	Zbirka::Node* tek = collection.prvi;

	while (tek)
	{
		out << *tek->card << endl;
		tek = tek->next;
	}

	return out;
}
