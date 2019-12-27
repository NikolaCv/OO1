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
		virtual string text() const
		{
			return "Ne postoji trenutni element. (CurrentElementDoesntExist)";
		};
	};

	class InvalidLongitudeOrLatitudeException :public Exception
	{
		virtual string text() const
		{
			return "Los format sirine i/ili duzine. (InvalidLongitudeOrLatitudeException)";
		};

	};

}

#endif