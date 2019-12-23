#ifndef KORISNIK_H
#define KORISNIK_H

#include "myExceptions.h"
#include <iostream>
#include <string>

using namespace std;

class Korisnik
{
public:
	Korisnik(const string name, const string password);
	Korisnik(const Korisnik& user) = default;
	Korisnik(Korisnik&& user) = default;
	Korisnik& operator=(const Korisnik& user) = default;
	Korisnik& operator=(Korisnik&& user) = default;
	~Korisnik() = default;

	void changePassword(const string old_password, const string new_password);
	friend bool operator==(const Korisnik& user1, const Korisnik& user2);
	friend bool operator!=(const Korisnik& user1, const Korisnik& user2);
	friend ostream& operator<<(ostream& out, const Korisnik& user);
	string getName() const;
	string getPassword() const;

private:
	string name, password;
	void checkPasswordFormat(const string password);
};

#endif