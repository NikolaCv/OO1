#ifndef LISTAOBAVESTENJA_H
#define LISTAOBAVESTENJA_H

#include "Obavestenje.h"

class ListaObavestenja
{
public:
	ListaObavestenja();
	~ListaObavestenja();
	ListaObavestenja(const ListaObavestenja& notification_list) = delete;
	ListaObavestenja(ListaObavestenja&& notification_list) = delete;
	ListaObavestenja& operator=(const ListaObavestenja& notification_list) = delete;
	ListaObavestenja& operator=(ListaObavestenja&& notification_list) = delete;
	ListaObavestenja& operator+=(Obavestenje* notification);//dodavanje notifikacije
	ListaObavestenja& operator()();//pisanje svih neprocitanih notifikacija
	int operator+();//return len
	ListaObavestenja& operator!();//cita notifikacije
	ListaObavestenja& operator~();//brise notifikacije
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

	void brisi();
};

#endif