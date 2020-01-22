#include <iostream>
using namespace std;

struct Tacka2D
{
public:
	float x;
	float y;
	Tacka2D()
	{
	}
	Tacka2D(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	friend ostream& operator<<(ostream&, const Tacka2D&);



};
ostream& operator<<(ostream& COUT, const Tacka2D& t) {
	cout << "X: " << t.x << " - Y: " << t.y;
	return COUT;
}
typedef Tacka2D Tip;
class Cvor {
public:
	Cvor * next;
	Tip vrijednost;
public:
	Cvor(Cvor * next, Tip vrijednost)
	{
		this->next = next;
		this->vrijednost = vrijednost;
	}

};

struct PrioritetniRedPov
{
	Cvor * prvi;
	float udaljenost(Tip t) {
		float kvadrat = pow(10 - t.x, 2) + pow(-5 - t.y, 2);
		float razlomak = sqrt(kvadrat);
		return razlomak;
	}
public:
	PrioritetniRedPov()
	{
		prvi = nullptr;
	}
	void Dodaj(Tip t) {

		Cvor *temp = prvi;
		Cvor * novi = new Cvor(nullptr, t);
		Cvor * pt = nullptr;

		while (temp != nullptr) {
			if ( udaljenost(t)<udaljenost(temp->vrijednost)) {
				break;
			}
			pt = temp;
			temp = temp->next;
		}
		if (pt == nullptr) {
			prvi = novi;
		}
		else {
			pt->next = novi;
		}
		novi->next = temp;
	}
	bool JelPrazan() {
		return prvi == nullptr;
	}
	Tacka2D Ukloni() {
		Cvor * temp = prvi;
		Tacka2D vrijednost = temp->vrijednost;
	
		prvi = prvi->next;
		return vrijednost;
	}

	void Print() {
		Cvor*temp = prvi;
		while (temp != nullptr) {
			cout << "Tacka ("<<temp->vrijednost.x<<","<< temp->vrijednost.y<<" ) ima udaljenost "<< udaljenost(temp->vrijednost)<<" od tacke A(10,-5)" << endl;
			temp = temp->next;
		}
		cout << endl;
	}
	
};


void main()
{
	PrioritetniRedPov* r = new PrioritetniRedPov;
	r->Dodaj(Tacka2D(5, 6));
	r->Dodaj(Tacka2D(7, -6));
	r->Dodaj(Tacka2D(8, 7));

	r->Print();
	r->Ukloni();
	cout << "Nakon uklanjanja tacke najblizoj tacki A(10,-5) -> " << endl;
	r->Print();
	system("pause");
}
