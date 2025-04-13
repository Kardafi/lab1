#pragma once
#include "ObiektSISO.h"
#include <vector>
#include <deque>
#include <random>



class ModelARX : public ObiektSISO {
private:
    std::vector<double> A; //parametry wielomianu -> A (mianownik) i B (licznik)
    std::vector<double> B;
	std::deque<double> pamiecWejscie; //pamieæ sygna³ów wejœciowych
	std::deque<double> pamiecWyjscie; //pamieæ sygna³ów wyjœciowych

    unsigned int opoznienie; //dyskretny czas opóŸnienia

    double mocSzumu;
    std::default_random_engine generator;
    std::normal_distribution<double>* rozkladSzumu;

    double dodajSzum();

public:
    ModelARX(const std::vector<double>& _A, const std::vector<double>& _B, unsigned int _k, int _mocSzumu);
    ~ModelARX();


    double symuluj(double wejscie) override;

    


};
