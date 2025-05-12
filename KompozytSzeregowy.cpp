#include "KompozytSzeregowy.h"

KompozytSzeregowy::KompozytSzeregowy()
{
}

KompozytSzeregowy::~KompozytSzeregowy()
{
	for (auto komponent : komponenty)
	{
		delete komponent;
	}
}

void KompozytSzeregowy::dodaj(Komponent* komponent)
{
	komponenty.push_back(komponent);
}

void KompozytSzeregowy::usun(Komponent* komponent)
{
	komponenty.remove(komponent);
	delete komponent;
}

Komponent* KompozytSzeregowy::getChild(int n)
{
	if(n < 0 || n >= komponenty.size())
		return nullptr; // Zwróæ nullptr, jeœli indeks jest nieprawid³owy
	auto it = komponenty.begin();
	std::advance(it, n);
	return *it; // Zwróæ wskaŸnik do komponentu
}

double KompozytSzeregowy::symuluj(double wejscie)
{
	//double wynik = 0;
	//for (auto o : komponenty) {
	//	wynik *= o->symuluj(wejscie);
	//}
	//return wynik;

	for (auto o : komponenty) {
		wejscie = o->symuluj(wejscie);
	}
	return wejscie;
}
