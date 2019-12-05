#include "ListaObavestenja.h"

ListaObavestenja & ListaObavestenja::operator()()
{
	Node* tek = prvi;
	while (tek)
	{
		if (tek->notification->isRead() == false)
		{
			cout << *tek->notification << endl;
		}
		tek = tek->next;
	}
	
	return *this;
}

int ListaObavestenja::operator+()
{
	return len;
}

ListaObavestenja & ListaObavestenja::operator!()
{
	Node* tek = prvi;
	while (tek)
	{
		tek->notification->readIt();
		tek = tek->next;
	}

	return *this;
}

ListaObavestenja & ListaObavestenja::operator~()
{
	brisi();

	return *this;
}

Obavestenje * ListaObavestenja::operator[](int i)
{
	Node* tek = prvi;

	while (tek)
	{
		if (tek->notification->getID() == i)
			break;
		tek = tek->next;
	}

	if (tek == nullptr)
		return nullptr;

	if(tek->notification->isRead() == false)
		return tek->notification;
	else
		return nullptr;
}

ListaObavestenja::ListaObavestenja():prvi(nullptr),posl(nullptr)
{
}

ListaObavestenja & ListaObavestenja::operator+=(Obavestenje * notification)
{
	Node* novi = new Node(notification);
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

ostream & operator<<(ostream & out, const ListaObavestenja& notification_list)
{
	ListaObavestenja::Node* tek = notification_list.prvi;
	while (tek)
	{
		out << *tek->notification;
		out << endl;
		tek = tek->next;
	}

	return out;
}
