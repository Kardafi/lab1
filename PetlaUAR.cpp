#include "PetlaUAR.h"


PetlaUAR::PetlaUAR(trybPracyPetli _tryb) : trybPracy(_tryb), poprzednieWyjscie(0.0)
{
}

void PetlaUAR::UstawTryb(trybPracyPetli tryb)
{
	trybPracy = tryb;
}

trybPracyPetli PetlaUAR::PobierzTryb() const
{
	return trybPracy;
}

void PetlaUAR::DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik)
{
	skladniki.push_back(skladnik);
}
void PetlaUAR::DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik, size_t index)
{
	if (index > skladniki.size()) index = skladniki.size();
	skladniki.insert(skladniki.begin() + index, skladnik);
}

void PetlaUAR::UsunSkladnik(size_t index)
{
	if (index < skladniki.size()) {
		skladniki.erase(skladniki.begin() + index);
	}
	else {
		std::cerr << "Indeks poza zakresem!" << std::endl;
	}
}

double PetlaUAR::symuluj(double wejscie)
{
	return 0.0;
}



