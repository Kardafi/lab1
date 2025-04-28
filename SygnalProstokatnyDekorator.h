#pragma once
#include "GeneratorDekorator.h"
class SygnalProstokatnyDekorator : public GeneratorDekorator
{
private:
    double amplituda;
    double czestotliwosc;
    double wypelnienie; // w procentach 0-100%
    int czas;

public:
    SygnalProstokatnyDekorator(Generator& generator, double _amplituda, double _czestotliwosc, double _wypelnienie);

    double generuj() override;
};

