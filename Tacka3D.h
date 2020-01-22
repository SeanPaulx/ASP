#pragma once
#include <iostream>
using namespace std;

class Tacka3D {
public:
	int x;
	int y;
	int z;

	friend ostream& operator<<(ostream& cout, Tacka3D& tacka)
	{
		cout << "(" << tacka.x << ", " << tacka.y << ", " << tacka.z << ")";

		return cout;
	}
	friend istream& operator>>(istream& cin, Tacka3D& tacka)
	{
		cout << "Kordinata x: ";
		cin >> tacka.x;
		cout << "Kordinata y: ";
		cin >> tacka.y;
		cout << "Kordinata z: ";
		cin >> tacka.z;

		return cin;
	}
	bool operator==(Tacka3D& desna)
	{
		return x == desna.x && y == desna.y && z == desna.z;
	}
};