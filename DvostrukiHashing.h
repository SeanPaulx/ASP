#pragma once
#include "Tacka3D.h"

class DvostrukiHashing {
	int max;
	int trenutno;
	Tacka3D* nizV;
	bool* nizZ;
	int Hash1(Tacka3D element) { return sqrt(pow(element.x, 2) / 3. + pow(element.y, 2) / 3. + pow(element.z, 2) / 3.); }
	int Hash2(Tacka3D element) { return sqrt(pow(element.x + element.y + element.z, 2)); }
public:
	DvostrukiHashing()
	{
		max = 15;
		trenutno = 0;
		nizV = new Tacka3D[max];
		nizZ = new bool[max];

		for (int i = 0; i < max; i++)
			nizZ[i] = false;
	}

	void Dodaj(Tacka3D element)
	{
		if (Puno())
			throw exception("Niz je pun.\n");

		int pozicija1 = Hash1(element);

		if (nizZ[pozicija1])
		{
			int pozicija2 = Hash2(element);
			int i = 1;

			while (true)
			{
				int pozicija = (pozicija1 + i * pozicija2) % max;

				if (!nizZ[pozicija])
				{
					nizV[pozicija] = element;
					nizZ[pozicija] = true;
					break;
				}
				i++;
			}
		}
		else
		{
			nizV[pozicija1] = element;
			nizZ[pozicija1] = true;
		}


		trenutno++;
	}
	Tacka3D Ukloni(Tacka3D element)
	{
		if (Prazno())
			throw exception("Nemam sta ukloniti.\n");

		int pozicija1 = Hash1(element);

		if (nizZ[pozicija1] && nizV[pozicija1] == element)
		{
			nizZ[pozicija1] = false;
			trenutno--;
			return nizV[pozicija1];
		}
		else
		{
			int pozicija2 = Hash2(element);
			int i = 1;

			while (i <= max)
			{
				int pozicija = (pozicija1 + i * pozicija2) % max;

				if (nizZ[pozicija] && nizV[pozicija] == element)
				{
					nizZ[pozicija] = false;
					trenutno--;
					return nizV[pozicija];
				}

				i++;
			}

		}
		throw exception("Element ne postoji.\n");
	}

	bool Puno() { return trenutno == max; }
	bool Prazno() { return trenutno == 0; }

	void Ispisi() {
		for (int i = 0; i < max; i++)
		{
			cout << i << " ---> ";
			if (nizZ[i])
				cout << nizV[i];
			cout << endl;
		}


		cout << endl;
	}
};