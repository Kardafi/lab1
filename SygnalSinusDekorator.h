#pragma once
#include "GeneratorDekorator.h"

constexpr auto M_PI = 3.14159265358979323846;

class SygnalSinusDekorator : public GeneratorDekorator
{
    double amplituda;
    double czestotliwosc;
    double a;        // wspó³czynnik: 2*cos(omega)

    double n1=0; //n-1 
	double n2=0; //n-2 

public:
    SygnalSinusDekorator(Generator& generator, double _amplituda, double _czestotliwosc);

    double generuj() override;

};

