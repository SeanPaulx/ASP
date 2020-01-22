#pragma once
#include <iostream>
#include "DvostrukiHashing.h"
using namespace std;

class DvostrukiHashingTest {

public:
	static void Test() {
		DvostrukiHashing hash;
		int izbor = 0;
		Tacka3D tacka;

		do {
			cout << "0. Izlaz" << endl;
			cout << "1. Dodaj" << endl;
			cout << "2. Ukloni" << endl;
			cout << "3. Ispisi" << endl << endl;

			cout << "Izbor: ";
			cin >> izbor;

			switch (izbor) {
			case 0:
				break;
			case 1:
				system("cls");

				cout << "UNOS TACKE\n";
				cin >> tacka;

				try
				{
					hash.Dodaj(tacka);
				}
				catch (const exception & ex)
				{
					cout << ex.what();
				}

				cout << endl << endl;

				break;
			case 2:
				system("cls");

				cout << "UNOS TACKE\n";
				cin >> tacka;

				try
				{
					tacka = hash.Ukloni(tacka);
					cout << "Uklonjena je tacka " << tacka << ".";
				}
				catch (const exception & ex)
				{
					cout << ex.what();
				}

				cout << endl << endl;

				break;
			case 3:
				system("cls");

				hash.Ispisi();

				cout << endl << endl;

				break;
			default:
				cout << "Probaj opet.";

				cout << endl << endl;

				break;
			}

		} while (izbor != 0);
	}
};