#include "Zbirka.h"
#include <time.h>


Zbirka::Zbirka():prvi(nullptr),posl(nullptr)
{
}

Zbirka::Zbirka(const Zbirka & collection)
{
	kopiraj(collection);
}

Zbirka::Zbirka(Zbirka && collection)
{
	premesti(collection);
}

Zbirka & Zbirka::operator=(const Zbirka & collection)
{
	if (this != &collection)
	{
		brisi();
		kopiraj(collection);
	}

	return *this;
}

Zbirka & Zbirka::operator=(Zbirka && collection)
{
	if (this != &collection)
	{
		brisi();
		premesti(collection);
	}

	return *this;
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
}

int Zbirka::getLength() const
{
	return len;
}

Karta * Zbirka::operator[](int index) const
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

Karta * Zbirka::operator[](unsigned id) const
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
		pret = tek;
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
				len--;
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
				len--;
				break;
			}
		}
		pret = tek;
		tek = tek->next;
	}
}

void Zbirka::operator~()
{
	srand(time(NULL));
	int a = rand();
	int ind = a % len;
	cout << a << endl << endl;
	(*this)(ind);
}

void Zbirka::kopiraj(const Zbirka & collection)
{
	for (int i = 0; i < collection.len; ++i)
	{
		if (typeid(collection[i]) == typeid(Carobnjak))
		{																//trenutno je jedini borac, a i karta koja postoji carobnjak
			Karta* temp = new Carobnjak(collection[i]->getName(),		//treba da se doda else za druge vrste karata (borce i carolije) kada se ubace
				collection[i]->getMagicEnergyNeeded(),
				collection[i]->getStrength());
			(*this) += temp;
		}
	}
	len = collection.getLength();
}

void Zbirka::premesti(Zbirka & collection)
{
	for (int i = 0; i < collection.len; ++i)
	{
		(*this) += collection[i];
	}
	len = collection.getLength();

	collection.brisi();
}

void Zbirka::brisi()
{
	while (prvi)
	{
		Node *tek = prvi;
		prvi = prvi->next;
		delete tek->card;
		delete tek;
	}
	posl = nullptr;
	len = 0;
}


Zbirka::~Zbirka()
{
	brisi();
}

ostream & operator<<(ostream & out, const Zbirka& collection)
{
	Zbirka::Node* tek = collection.prvi;
	while (tek)
	{
		out << *tek->card;
		out << endl;
		tek = tek->next;
	}

	return out;
}
