#pragma once
#include "ObiektSISO.h"
#include <vector>
#include <deque>
#include <random>



class ModelARX : public ObiektSISO {
private:
    std::vector<double> A; //parametry wielomianu -> A (mianownik) i B (licznik)
    std::vector<double> B;
	std::deque<double> pamiecWejscie; //pamie� sygna��w wej�ciowych
	std::deque<double> pamiecWyjscie; //pamie� sygna��w wyj�ciowych

    unsigned int opoznienie; //dyskretny czas op�nienia

    double mocSzumu;
    std::default_random_engine generator;
    std::normal_distribution<double>* rozkladSzumu;

    double dodajSzum();

public:
    ModelARX(const std::vector<double>& _A, const std::vector<double>& _B, unsigned int _k, int _mocSzumu);
    ~ModelARX();


    double symuluj(double wejscie) override;

    


};
