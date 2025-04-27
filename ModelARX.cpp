#include "ModelARX.h"
#include <numeric> 

ModelARX::ModelARX(const std::vector<double>& _A, const std::vector<double>& _B, unsigned int _k, int _mocSzumu) : A(_A), B(_B), opoznienie(_k), mocSzumu(_mocSzumu)
{
    pamiecWejscie.resize(B.size() + opoznienie, 0.0);
    pamiecWyjscie.resize(A.size(), 0.0);

    if (mocSzumu > 0.0) {
        rozkladSzumu = new std::normal_distribution<double>(0.0, mocSzumu);
    }
    else {
        rozkladSzumu = nullptr;  // Nie tworzysz obiektu, jeœli mocSzumu = 0
    }

}

ModelARX::~ModelARX() {
    if (rozkladSzumu != nullptr) {
        delete rozkladSzumu;
    }
}


double ModelARX::dodajSzum() {
    if (rozkladSzumu != nullptr) {
        // Generowanie szumu na podstawie rozk³adu normalnego
        return (*rozkladSzumu)(generator);
	}
	else {
		return 0.0; // Brak szumu
	}
}

double ModelARX::symuluj(double wejscie) {
	pamiecWejscie.push_front(wejscie); //dodanie wejscia do pamieci
    pamiecWejscie.pop_back();

	double wynik = std::inner_product(B.begin(), B.end(), pamiecWejscie.begin() + opoznienie, 0.0); //iloczyn skalarny wspolczynnika B i pamieci wejscia
	wynik -= std::inner_product(A.begin(), A.end(), pamiecWyjscie.begin(), 0.0); //iloczyn skalarny wspolczynnika A i pamieci wyjscia
	//wynik += dodajSzum(); //dodanie szumu


	pamiecWyjscie.push_front(wynik); //aktualizacja pamieci wyjscia
    pamiecWyjscie.pop_back();

    return wynik;
}

//todo d³uzsza degue zeby przechowywac opóŸnienie (k) o tyle ile k i mno¿enie robimy ustawiaj¹c iteratory
// pierwsze elementy bed¹ pomijane
//                          a               b         k, szum
//ModelARX instancjaTestowa({ -0.4,0.2 }, { 0.6, 0.3 }, 2, 0);