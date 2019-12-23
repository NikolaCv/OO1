#ifndef LISTA_H
#define LISTA_H

#include "myExceptions.h"

//TODO: template specialization for pointer types

template <class T>
class Lista
{
public:
	Lista();
	Lista(const Lista& list);
	Lista(Lista&& list);
	Lista& operator=(const Lista& list);
	Lista& operator=(Lista&& list);
	~Lista();

	int getLength();
	Lista& operator+=(T new_data);
	T& operator[](int index);
	T operator[](int index) const;
	void operator()(int index);
	friend ostream& operator<<(ostream & out, const Lista& list);

private:
	struct Node
	{
		T data;
		Node* next;
		Node(T data) :data(data), next(nullptr) {}
	};

	Node* start, *end;
	int length;

	void del();
	void copy(const Lista& list);
	void move(Lista& list);
};

template<class T>
inline Lista<T>::Lista():start(nullptr),end(nullptr),length(0)
{
}

template<class T>
Lista<T>::Lista(const Lista & list)
{
	copy(list);
}

template<class T>
Lista<T>::Lista(Lista && list)
{
	move(list);
}

template<class T>
Lista<T> & Lista<T>::operator=(const Lista & list)
{
	{
		if (this != &list)
		{
			del();
			copy(list);
		}

		return *this;
	}
}

template<class T>
Lista<T> & Lista<T>::operator=(Lista && list)
{
	if (this != &list)
	{
		del();
		copy(list);
	}

	return *this;
}

template<class T>
Lista<T>::~Lista()
{
	del();
}

template<class T>
inline int Lista<T>::getLength()
{
	return length;
}

template<class T>
inline Lista<T> & Lista<T>::operator+=(T new_data)
{
	Node* new_node = new Node(new_data);
	if (end == nullptr)
		start = new_node;
	else
		end->next = new_node;

	end = new_node;
	length++;

	return *this;
}

template<class T>
T & Lista<T>::operator[](int index)
{
	if (index < 0) throw myExceptions::InvalidIndexException();
	Node* temp = start;
	int i = 0;
	while (temp)
	{
		if (i == index) break;
		temp = temp->next;
		i++;
	}

	if (temp == nullptr) throw myExceptions::InvalidIndexException();

	return temp->data;
}

template<class T>
T Lista<T>::operator[](int index) const
{
	if (index < 0) throw myExceptions::InvalidIndexException();
	Node* temp = start;
	int i = 0;
	while (temp)
	{
		if (i == index) break;
		temp = temp->next;
		i++;
	}

	if (temp == nullptr) throw myExceptions::InvalidIndexException();

	return temp->data;
}

template<class T>
void Lista<T>::operator()(int index)
{
	if (index < 0) throw myExceptions::InvalidIndexException();
	Node* temp = start, * last = nullptr;
	int i = 0;
	while (temp)
	{
		if (i == index) break;
		last = temp;
		temp = temp->next;
		i++;
	}

	if (temp == nullptr) throw myExceptions::InvalidIndexException();

	if (last == nullptr)
	{
		temp = start;
		start = start->next;
		delete temp;
	}
	else
	{
		last->next = temp->next;
		delete temp;
	}
}

template<class T>
void Lista<T>::del()
{
	Node* temp = start;

	while (start)
	{
		start = start->next;
		delete temp;
		temp = start;
	}
	start = end = nullptr;
	length = 0;
}

template<class T>
void Lista<T>::copy(const Lista& list)
{
	Node* temp = list.start;
	while (temp)
	{
		(*this) += temp->data;
		temp = temp->next;
	}
	length = list.length;
}

template<class T>
inline void Lista<T>::move(Lista & list)
{
	start = list.start;
	end = list.end;
	length = list.length;
}

template<class T>
ostream & operator<<(ostream & out, const Lista<T> & list)
{
	for (int i = 0; i < list.length; ++i)
		cout << list[i] << endl;
	return out;
}


#endif