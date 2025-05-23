#include "SygnalSinusDekorator.h"
#include <cmath>

SygnalSinusDekorator::SygnalSinusDekorator(Generator& generator, double _amplituda, double _czestotliwosc, double _probkowanie) : GeneratorDekorator(generator), amplituda(_amplituda), czestotliwosc(_czestotliwosc), probkowanie(_probkowanie)
{
    omega = 2.0 * M_PI * czestotliwosc;
    n1 = _amplituda*sin(omega);     
    n2 = 0;
}

double SygnalSinusDekorator::generuj() 
{
    double xn = 2 * cos(omega) * n1 - n2;
    n2 = n1;
    n1 = xn;
    return xn + GeneratorDekorator::generuj();
}
