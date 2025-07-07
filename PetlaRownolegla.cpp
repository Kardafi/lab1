#include "PetlaRownolegla.h"

void PetlaRownolegla::UstawTryb(trybPracyPetli tryb)
{
	trybPracy = tryb;
}

trybPracyPetli PetlaRownolegla::PobierzTryb() const
{
	return trybPracy;
}

void PetlaRownolegla::DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik)
{
	skladniki.push_back(skladnik);
}

void PetlaRownolegla::DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik, size_t index)
{
	if (index > skladniki.size()) index = skladniki.size();
	skladniki.insert(skladniki.begin() + index, skladnik);
}

void PetlaRownolegla::UsunSkladnik(size_t index)
{
	if (index < skladniki.size()) {
		skladniki.erase(skladniki.begin() + index);
	}
	else {
		std::cerr << "Indeks poza zakresem!" << std::endl;
	}
}

double PetlaRownolegla::symuluj(double wejscie)
{
    if (skladniki.empty()) return 0.0;
    double uchyb = wejscie;
    if (trybPracy == trybPracyPetli::ZAMKNIETA) {
        uchyb = wejscie - poprzednieWyjscie;
    }
    double suma = 0.0;
    for (auto& s : skladniki) {
        suma += s->symuluj(uchyb);
    }
    if (trybPracy == trybPracyPetli::ZAMKNIETA) {
        poprzednieWyjscie = suma;
    }
    return suma;
}