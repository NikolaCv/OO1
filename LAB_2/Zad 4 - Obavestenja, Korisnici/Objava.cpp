#include "Objava.h"
#include <string>

Objava::Objava(Korisnik * user, const string text):Obavestenje(user),text(text)
{
}

string Objava::toString() const
{
	return text;
}
