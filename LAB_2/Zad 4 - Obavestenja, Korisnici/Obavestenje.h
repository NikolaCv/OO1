#ifndef OBAVESTENJE_H
#define OBAVESTENJE_H

#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Korisnik;

class Obavestenje
{
public:
	Obavestenje(Korisnik* user);
	Obavestenje(const Obavestenje& notification);
	Obavestenje(Obavestenje&& notification);
	Obavestenje& operator=(const Obavestenje& notification);
	Obavestenje& operator=(Obavestenje&& notification);
	~Obavestenje();
	void readIt();	//"procitaj obavestenje"
	bool isRead() const;	//proveri je li procitano
	int getID() const;
	Korisnik* getUser() const;
	virtual string toString() const;//za ispisivanje dodatnih stvari za izvedene klase; za ovu vraca prazan string, za objavu vraca tekst
											//tj. "specifican deo obavestenja"
	friend ostream& operator<<(ostream& out, const Obavestenje& notification);
	Obavestenje* kopija() const;
	void addUser(Korisnik *user);

protected:
	void kopiraj(const Obavestenje& notification); //pretpostavka, kada se kopira, novo obavestenje dobija novi id i novo vreme
	void premesti(Obavestenje& notification);

private:
	Korisnik *user = nullptr;
	time_t notif_time = time(NULL);
	bool is_read = false;
	static int statID;
	int ID = ++statID;
};

#endif