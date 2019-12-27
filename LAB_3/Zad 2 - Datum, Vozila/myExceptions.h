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

	class CurrentElementDoesntExist:public Exception
	{
		virtual string text() const override
		{
			return "Ne postoji trenutni element. (CurrentElementDoesntExist)";
		};
	};

	class InvalidDateIndexException :public Exception
	{
		virtual string text() const override
		{
			return "Nepostojeci indeks za datum. (InvalidDateIndexException)";
		};
	};

	class InvalidDateFormatException :public Exception
	{
		virtual string text() const override
		{
			return "Los format datuma. (InvalidDateFormatException)";
		};
	};

	class FirstDateIsBeforeSecondException :public Exception
	{
		virtual string text() const override
		{
			return "Oduzimanje datuma je bio negativan broj. (FirstDateIsBeforeSecondException)";
		};
	};

}

#endif