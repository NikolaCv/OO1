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
}

#endif