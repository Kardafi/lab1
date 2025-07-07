#include "PetlaSzeregowa.h"

void PetlaSzeregowa::UstawTryb(trybPracyPetli tryb)
{
	trybPracy = tryb;
}

trybPracyPetli PetlaSzeregowa::PobierzTryb() const
{
	return trybPracy;
}

void PetlaSzeregowa::DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik)
{
	skladniki.push_back(skladnik);
}

void PetlaSzeregowa::DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik, size_t index)
{
	if (index > skladniki.size()) index = skladniki.size();
	skladniki.insert(skladniki.begin() + index, skladnik);
}

void PetlaSzeregowa::UsunSkladnik(size_t index)
{
	if (index < skladniki.size()) {
		skladniki.erase(skladniki.begin() + index);
	}
	else {
		std::cerr << "Indeks poza zakresem!" << std::endl;
	}
}

double PetlaSzeregowa::symuluj(double wejscie)
{
	if (skladniki.empty()) return 0.0;

	double sygnal = wejscie;
	if (trybPracy == trybPracyPetli::ZAMKNIETA) {
		sygnal = wejscie - poprzednieWyjscie;
	}
	for (auto& s : skladniki) {
		sygnal = s->symuluj(sygnal);
	}
	if (trybPracy == trybPracyPetli::ZAMKNIETA) {
		poprzednieWyjscie = sygnal;
	}
	return sygnal;
}
