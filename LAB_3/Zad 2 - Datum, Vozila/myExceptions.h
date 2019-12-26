#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include <iostream>
#include <string>

using namespace std;

namespace myExceptions
{
	class CurrentElementDoesntExist
	{
		friend ostream& operator<<(ostream& out, const CurrentElementDoesntExist& p)
		{
			return out << "Ne postoji trenutni element. (CurrentElementDoesntExist)" << endl;
		}
	};

	class InvalidDateIndexException
	{
		friend ostream& operator<<(ostream& out, const InvalidDateIndexException& p)
		{
			return out << "Nepostojeci indeks za datum. (InvalidDateIndexException)" << endl;
		}
	};

	class InvalidDateFormatException
	{
		friend ostream& operator<<(ostream& out, const InvalidDateFormatException& p)
		{
			return out << "Los format datuma. (InvalidDateFormatException)" << endl;
		}
	};

	class FirstDateIsBeforeSecondException
	{
		friend ostream& operator<<(ostream& out, const FirstDateIsBeforeSecondException& p)
		{
			return out << "Oduzimanje datuma je bio negativan broj. (FirstDateIsBeforeSecondException)" << endl;
		}
	};

}

#endif