#ifndef LISTA_H
#define LISTA_H

#include "myExceptions.h"
#include <iostream>
using namespace std;

#include "myExceptions.h"

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

	int getLength() const;
	Lista& operator+=(const T& new_data);
	void moveCurrent() const;
	void moveCurrentAtStart() const;
	bool doesCurrentExist() const;
	T& getCurrentData();
	const T& getCurrentdata() const;
	void deleteCurrent();

	template <class T>
	friend ostream& operator<<(ostream & out, const Lista<T> &list);

private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
		Node(const T& data) :data(data), next(nullptr), prev(nullptr) {}
	};

	Node* start, *end;
	mutable Node* current;
	int length;

	void del();
	void copy(const Lista& list);
	void move(Lista& list);
};

template<class T>
inline Lista<T>::Lista() :start(nullptr), end(nullptr), current(nullptr), length(0)
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
inline int Lista<T>::getLength() const
{
	return length;
}

template<class T>
inline Lista<T> & Lista<T>::operator+=(const T& new_data)
{
	Node* new_node = new Node(new_data);
	if (end == nullptr)
		start = new_node;
	else
	{
		end->next = new_node;
		new_node->prev = end;
	}

	end = new_node;
	length++;

	return *this;
}

template<class T>
inline void Lista<T>::moveCurrent() const
{
	if (current == nullptr) throw myExceptions::CurrentElementDoesntExist();

	current = current->next;
}

template<class T>
inline void Lista<T>::moveCurrentAtStart() const
{
	current = start;
}

template<class T>
inline bool Lista<T>::doesCurrentExist() const
{
	return (current == nullptr) ? false : true;
}

template<class T>
inline T & Lista<T>::getCurrentData()
{
	if (current == nullptr) throw myExceptions::CurrentElementDoesntExist();

	return current->data;
}

template<class T>
inline const T & Lista<T>::getCurrentdata() const
{
	if (current == nullptr) throw myExceptions::CurrentElementDoesntExist();

	return current->data;
}

template<class T>
inline void Lista<T>::deleteCurrent()
{
	if (current == nullptr) throw myExceptions::CurrentElementDoesntExist();

	if (current->prev == nullptr)
	{
		current = current->next;
		start = current;
		start->prev->next = nullptr;
		delete start->prev;
		start->prev = nullptr;
	}
	else if (current->next == nullptr)
	{
		current = current->prev;
		end = current;
		end->next->prev = nullptr;
		delete end->next;
		end->next = nullptr;
	}
	else
	{
		current->prev->next = current->next;
		Node* temp = current->next;
		current->next->prev = current->prev;
		current->prev = nullptr;
		current->next = nullptr;
		delete current;
		current = temp;
	}

	length--;
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
	list.end = nullptr;
	list.start = nullptr;
	list.length = 0;
}

template<class T>
ostream & operator<<(ostream & out, const Lista<T> & list)
{
	auto temp = list.start;
	while (temp)
	{
		out << temp->data << endl;
		temp = temp->next;
	}
	return out;
}

//specialization for pointer types-----------------------------------------------------------------

template <class T>
class Lista<T*>
{
public:
	Lista();
	Lista(const Lista& list) = delete;
	Lista(Lista&& list) = delete;
	Lista& operator=(const Lista& list) = delete;
	Lista& operator=(Lista&& list) = delete;
	~Lista();//spec

	int getLength() const;
	Lista& operator+=(T* new_data);//spec
	void moveCurrent() const;
	void moveCurrentAtStart() const;
	bool doesCurrentExist() const;
	T* getCurrentData();//spec
	const T* getCurrentdata() const;//spec
	void deleteCurrent();//spec			----------TODO: ne ponavljaj se

	template <class T>
	friend ostream& operator<<(ostream & out, const Lista<T*> &list);

private:
	struct Node
	{
		T* data;
		Node* next;
		Node* prev;
		Node(T* data) :data(data), next(nullptr), prev(nullptr) {}
	};

	Node* start, *end;
	mutable Node* current;
	int length;

	void del();//spec
	void copy(const Lista& list);
	void move(Lista& list);
};

template<class T>
inline Lista<T*>::Lista() :start(nullptr), end(nullptr), current(nullptr), length(0)
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
Lista<T*> & Lista<T*>::operator=(const Lista & list)
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
Lista<T*> & Lista<T*>::operator=(Lista && list)
{
	if (this != &list)
	{
		del();
		copy(list);
	}

	return *this;
}

template<class T>
Lista<T*>::~Lista()
{
	del();
}

template<class T>
inline int Lista<T*>::getLength() const
{
	return length;
}

template<class T>
inline Lista<T*> & Lista<T*>::operator+=(T* new_data)
{
	Node* new_node = new Node(new_data);
	if (end == nullptr)
		start = new_node;
	else
	{
		end->next = new_node;
		new_node->prev = end;
	}

	end = new_node;
	length++;

	return *this;
}

template<class T>
inline void Lista<T*>::moveCurrent() const
{
	if (current == nullptr) throw myExceptions::CurrentElementDoesntExist();

	current = current->next;
}

template<class T>
inline void Lista<T*>::moveCurrentAtStart() const
{
	if (current == nullptr) throw myExceptions::CurrentElementDoesntExist();

	current = start;

}

template<class T>
inline bool Lista<T*>::doesCurrentExist() const
{
	return (current == nullptr) ? false : true;
}

template<class T>
inline T * Lista<T*>::getCurrentData()
{
	if (current == nullptr) throw myExceptions::CurrentElementDoesntExist();

	return current->data;
}

template<class T>
inline const T * Lista<T*>::getCurrentdata() const
{
	if (current == nullptr) throw myExceptions::CurrentElementDoesntExist();

	return current->data;
}

template<class T>
inline void Lista<T*>::deleteCurrent()
{
	if (current == nullptr) throw myExceptions::CurrentElementDoesntExist();

	if (current->prev == nullptr)
	{
		current = current->next;
		start = current;
		delete start->data;
		delete start->prev;
		start->prev = nullptr;
	}
	else if (current->next == nullptr)
	{
		current = current->prev;
		end = current;
		delete end->data;
		delete end->next;
		end->next = nullptr;
	}
	else
	{
		current->prev->next = current->next;
		Node* temp = current->next;
		current->next->prev = current->prev;
		delete current->data;
		delete current;
		current = temp;
	}

	length--;
}

template<class T>
void Lista<T*>::del()
{
	Node* temp = start;

	while (start)
	{
		start = start->next;
		delete temp->data;
		delete temp;
		temp = start;
	}
	start = end = nullptr;
	length = 0;
}

template<class T>
void Lista<T*>::copy(const Lista& list)
{
	Node* temp = list.start;
	while (temp)
	{
		(*this) += new T(*temp->data);
		temp = temp->next;
	}
	length = list.length;
}

template<class T>
inline void Lista<T*>::move(Lista & list)
{
	start = list.start;
	end = list.end;
	length = list.length;
	list.end = nullptr;
	list.start = nullptr;
	list.length = 0;
}

template<class T>
ostream & operator<<(ostream & out, const Lista<T*> & list)
{
	auto temp = list.start;
	while (temp)
	{
		out << *temp->data << endl;
		temp = temp->next;
	}
	return out;
}

#endif