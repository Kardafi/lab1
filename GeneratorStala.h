#pragma once
#include "Generator.h"
class GeneratorStala : public Generator
{
private:
    double wartosc;
public:
    GeneratorStala(double _wartosc=0);

    double generuj() override;

};

