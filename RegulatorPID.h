#pragma once
#include "ObiektSISO.h"
#include <vector>
#include <deque>
#include <iostream>

class RegulatorPID :
    public ObiektSISO
{
    double k; //wzmocnienie
    double Ti; //czas calkowania
    double Td; //czas rozniczkowania
    std::vector<double> pamiecUchyl; //pamieæ sygna³ów wejœciowych

public:
    RegulatorPID(double _k);
    RegulatorPID(double _k, double _Ti);
    RegulatorPID(double _k, double _Ti, double _Td);
    ~RegulatorPID();

    double symuluj(double wejscie) override;

    void setK(double _k);
    void setTi(double _Ti);
    void setTd(double _Td);

private:
    int SprawdzNastawe(double _nastawa); //sprawdza czy nastawa jest dodatnia -> return 1 = ok
};

