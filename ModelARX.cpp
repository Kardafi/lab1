#include "ModelARX.h"
#include <numeric> 

#include <fstream>
#include <sstream>

ModelARX::ModelARX(const std::vector<double>& _A, const std::vector<double>& _B, unsigned int _k, int _mocSzumu) : A(_A), B(_B), opoznienie(_k), mocSzumu(_mocSzumu)
{   
    if (opoznienie < 0)opoznienie = 0;
    if (mocSzumu < 0)mocSzumu = 0;

    pamiecWejscie.resize(B.size() + opoznienie, 0.0);
    pamiecWyjscie.resize(A.size(), 0.0);

    if (mocSzumu > 0.0) {
        rozkladSzumu = new std::normal_distribution<double>(0.0, mocSzumu);
    }
    else {
        rozkladSzumu = nullptr;  // Nie tworzysz obiektu, jeœli mocSzumu = 0
    }

}

ModelARX::ModelARX(const std::string& sciezkaPliku)
    : rozkladSzumu(nullptr), mocSzumu(0.0) // ¿eby by³o bezpiecznie w razie wyj¹tków
{
    std::ifstream file(sciezkaPliku);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string label;
        iss >> label;
        
        if (label == "A:") {
            double val;
            while (iss >> val) A.push_back(val);
        }
        else if (label == "B:") {
            double val;
            while (iss >> val) B.push_back(val);
        }
        else if (label == "k:") {
            iss >> opoznienie;
        }
        else if (label == "szum:") {
            iss >> mocSzumu;
        }
    }

    if (opoznienie < 0)opoznienie = 0;
    if (mocSzumu < 0)mocSzumu = 0;

    pamiecWejscie.resize(B.size() + opoznienie, 0.0);
    pamiecWyjscie.resize(A.size(), 0.0);

    if (mocSzumu > 0.0) {
        rozkladSzumu = new std::normal_distribution<double>(0.0, mocSzumu);
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

void ModelARX::ZapiszDoPlikuJSON(const std::string& filename) const {
    std::ofstream file(filename);
  //  file << std::fixed << std::setprecision(6); // dok³adnoœæ liczb zmiennoprzecinkowych

    file << "{\n";

    // A
    file << "  \"A\": [";
    for (size_t i = 0; i < A.size(); ++i) {
        file << A[i];
        if (i < A.size() - 1) file << ", ";
    }
    file << "],\n";

    // B
    file << "  \"B\": [";
    for (size_t i = 0; i < B.size(); ++i) {
        file << B[i];
        if (i < B.size() - 1) file << ", ";
    }
    file << "],\n";

    file << "  \"opoznienie\": " << opoznienie << ",\n";
    file << "  \"mocSzumu\": " << mocSzumu << "\n";

    file << "}\n";
}

double ModelARX::symuluj(double wejscie) {
	pamiecWejscie.push_front(wejscie); //dodanie wejscia do pamieci
    pamiecWejscie.pop_back();

	double wynik = std::inner_product(B.begin(), B.end(), pamiecWejscie.begin() + opoznienie, 0.0); //iloczyn skalarny wspolczynnika B i pamieci wejscia
	wynik -= std::inner_product(A.begin(), A.end(), pamiecWyjscie.begin(), 0.0); //iloczyn skalarny wspolczynnika A i pamieci wyjscia
    wynik += dodajSzum(); //dodanie szumu


	pamiecWyjscie.push_front(wynik); //aktualizacja pamieci wyjscia
    pamiecWyjscie.pop_back();

    return wynik;
}
