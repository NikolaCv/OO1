#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include <iostream>
#include <string>

using namespace std;

namespace myExceptions
{
	class BadPassFormatException
	{
		friend ostream& operator<<(ostream& out, const BadPassFormatException& p)
		{
			return out << "Lozinka nije odgovarajuceg formata. (BadPassFormatException)" << endl;
		}
	};
	class IncorrectPasswordException
	{
		friend ostream& operator<<(ostream& out, const IncorrectPasswordException& p)
		{
			return out << "Pogresna lozinka. (IncorrectPasswordException)" << endl;
		}
	};

	class InvalidIndexException
	{
		friend ostream& operator<<(ostream& out, const InvalidIndexException& p)
		{
			return out << "Ne postoji podatak na zadatoj poziciji. (InvalidIndexException)" << endl;
		}
	};

	class UserAlreadyExistsException
	{
		friend ostream& operator<<(ostream& out, const UserAlreadyExistsException& p)
		{
			return out << "Korisnik vec postoji u evidenciji. (UserAlreadyExistsException)" << endl;
		}
	};
	class UserDoesntExistException
	{
		friend ostream& operator<<(ostream& out, const UserDoesntExistException& p)
		{
			return out << "Korisnik ne postoji u evidenciji. (UserDoesntExistException)" << endl;
		}
	};
}

#endif