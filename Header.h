#pragma once
#include <iostream>
#include <ctime>
#include <list>
using namespace std;

#define Adresse_mit_Telefonliste
//#define Telefonnummer_mit_Adresse

class Datum
{
public:
	Datum();
	Datum(unsigned int Tag, unsigned int Monat, unsigned int Jahr) : Tag(Tag), Monat(Monat), Jahr(Jahr) {};
	unsigned int Jahr;
	unsigned int Monat;
	unsigned int Tag;
};

#ifndef Telefonnummer_mit_Adresse
template<typename Typ>
#endif
class Adresse
{
public:
	Adresse() { Alter = 0; Plz = 0; };
	Adresse(string Name, Datum Geburtsdatum, string Strasse, unsigned int Plz, string Ort) : Name(Name),
		Geburtsdatum(Geburtsdatum),
		Strasse(Strasse),
		Plz(Plz),
		Ort(Ort)
	{
																						 
		time_t t = time(nullptr);
		tm* now = new tm();
		localtime_s(now, &t);
		Alter = now->tm_year + 1900 - Geburtsdatum.Jahr;
	}
	unsigned int getAlter()
	{
		return Alter;
	}

	/*
	* zu beachten: 
	* Das überladen des operator << erfordert bei Template-Klassen die friend-deklaration, damit 
	* das Objekt des Template Typ Parameters als 2. Argument übergeben werden kann.
	* Eine externe Deklaration ist nicht nötig, wird meist aber empfolen
	*/
	friend ostream& operator<< (ostream& rhs, Adresse a)
	{
		rhs << a.Name.c_str() << endl 
			<< a.Strasse.c_str() << endl 
			<< a.Plz << " " << a.Ort.c_str() << endl << endl;
		return rhs;
	}
	// Alternative:
	void getAdr()
	{
		cout << this->Name.c_str() << endl
			<< this->Strasse.c_str() << endl
			<< this->Plz << " " << this->Ort.c_str() << endl << endl;
	}

#ifndef Telefonnummer_mit_Adresse
	list<Typ>* Nummernliste = new list<Typ>();
#endif

private:
	string Name;
	Datum Geburtsdatum;
	unsigned int Plz;
	string Ort;
	string Strasse;
	unsigned int Alter;
};

#ifndef Adresse_mit_Telefonliste
template<typename Typ>
#endif
class Telefon
{
public:
	Telefon(string Nummer, string Art) : Nummer(Nummer), Art(Art) {};
	/*
	* zu beachten:
	* Das überladen des operator << erfordert bei Template-Klassen die friend-deklaration, damit
	* das Objekt des Template Typ Parameters als 2. Argument übergeben werden kann.
	* Eine externe Deklaration ist nicht nötig, wird meist aber empfolen
	*/
	friend ostream& operator<< (ostream& rhs, Telefon t)
	{
		rhs << t.Nummer.c_str() << ", " << t.Art.c_str() << endl;
		return rhs;
	}
	string Nummer;
	string Art;

#ifndef Adresse_mit_Telefonliste
	list<Typ>* Adressliste = new list<Typ>();
#endif

private:
};