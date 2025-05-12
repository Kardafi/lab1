#include "KompozytRownolegly.h"

KompozytRownolegly::KompozytRownolegly()
{
}

KompozytRownolegly::~KompozytRownolegly()
{
	for (auto komponent : komponenty)
	{
		delete komponent;
	}
}

void KompozytRownolegly::dodaj(Komponent* komponent)
{
	komponenty.push_back(komponent);
}

void KompozytRownolegly::usun(Komponent* komponent)
{
	komponenty.remove(komponent);
	delete komponent;
}

Komponent* KompozytRownolegly::getChild(int n)
{
	if (n < 0 || n >= komponenty.size())
		return nullptr; // Zwróæ nullptr, jeœli indeks jest nieprawid³owy
	auto it = komponenty.begin();
	std::advance(it, n);
	return *it; // Zwróæ wskaŸnik do komponentu
}

double KompozytRownolegly::symuluj(double wejscie)
{
	double wynik = 0;
	for (auto o : komponenty) {
		wynik += o->symuluj(wejscie);
	}
	return wynik;
}
