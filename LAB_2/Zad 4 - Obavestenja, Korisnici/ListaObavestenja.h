#ifndef LISTAOBAVESTENJA_H
#define LISTAOBAVESTENJA_H

#include "Obavestenje.h"

class ListaObavestenja
{
public:
	ListaObavestenja();
	ListaObavestenja(const ListaObavestenja& notification_list) = delete;
	ListaObavestenja(ListaObavestenja&& notification_list) = delete;
	ListaObavestenja& operator=(const ListaObavestenja& notification_list) = delete;
	ListaObavestenja& operator=(ListaObavestenja&& notification_list) = delete;
	ListaObavestenja& operator+=(Obavestenje* notification);
	ListaObavestenja& operator()();
	int operator+();
	ListaObavestenja& operator!();
	ListaObavestenja& operator~();
	Obavestenje* operator[](int i);
	friend ostream& operator<<(ostream & out, const ListaObavestenja& notification_list);

private:
	struct Node
	{
		Obavestenje* notification;
		Node* next;
		Node(Obavestenje * n):next(nullptr)//konstruktor za strukturu(listu)
		{
			notification = n;
		}
	};

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