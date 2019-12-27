#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include <iostream>
#include <string>

using namespace std;

namespace myExceptions
{
	class Exception
	{
		virtual string text() const
		{
			return "Exception.";
		};
		friend ostream& operator<<(ostream& out, const Exception& p)
		{
			return out << p.text() << endl;
		}
	};
	class BadPassFormatException: public Exception
	{
		string text() const override
		{
			return "Lozinka nije odgovarajuceg formata. (BadPassFormatException)";
		}

	};
	class IncorrectPasswordException : public Exception
	{
		string text() const override
		{
			return "Pogresna lozinka. (IncorrectPasswordException)";
		}
	};

	class InvalidIndexException : public Exception
	{
		string text() const override
		{
			return "Ne postoji podatak na zadatoj poziciji. (InvalidIndexException)";
		}
	};

	class UserAlreadyExistsException : public Exception
	{
		string text() const override
		{
			return "Korisnik vec postoji u evidenciji. (UserAlreadyExistsException)";
		}
	};
	class UserDoesntExistException : public Exception
	{
		string text() const override
		{
			return "Korisnik ne postoji u evidenciji. (UserDoesntExistException)";
		}
	};
}

#endif