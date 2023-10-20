#include "Header.h"
#include <list>
using namespace std;

void main()
{
#ifndef Telefonnummer_mit_Adresse
	{
		Adresse<Telefon>* pAdr = new Adresse<Telefon>(
				"Gerhard Biebl",
				Datum(14, 11, 1954),
				"Neustadtstr. 15",
				85368,
				"Moosburg an der Isar"
		);
		pAdr->Nummernliste->push_back(Telefon("089-12345", "geschäftlich"));
		pAdr->Nummernliste->push_back(Telefon("08161-63469", "privat"));
		pAdr->Nummernliste->push_back(Telefon("0176-555555", "Handy privat"));
		pAdr->Nummernliste->push_back(Telefon("0176-123445", "Handy geschäftlich"));

		cout << "Adresse: " << endl << endl;
		//pAdr->getAdr();

		cout << *pAdr;
		cout << "Alter: " << pAdr->getAlter() << " Jahre" << endl;

		cout << endl << "Telefonliste:" << endl << endl;

		for (list<Telefon>::iterator i = pAdr->Nummernliste->begin(); i != pAdr->Nummernliste->end(); i++)
		{
			cout << *i;
			//cout << i->Nummer.c_str() << ", " << i->Art.c_str() << endl;
		}
	}
#endif
#ifndef Adresse_mit_Telefonliste
	{
		Telefon<Adresse>* pTel = new Telefon<Adresse>("0123-2345", "Zu Hause");
		pTel->Adressliste->push_back(Adresse(
			"Gerhard Biebl",
			Datum(14, 11, 1954),
			"Neustadtstr. 15",
			85368,
			"Moosburg an der Isar"
		)
		);

		cout << " Telefonnummer:" << endl;
		cout << *pTel << endl;
		cout << "Teilnehmer: " << endl;
		for (list<Adresse>::iterator i = pTel->Adressliste->begin(); i != pTel->Adressliste->end(); i++)
		{
			cout << *i;
		}
	}
#endif
};