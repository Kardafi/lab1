#include "SygnalSinusDekorator.h"
#include <cmath>

SygnalSinusDekorator::SygnalSinusDekorator(Generator& generator, double _amplituda, double _czestotliwosc) : GeneratorDekorator(generator), amplituda(_amplituda), czestotliwosc(_czestotliwosc)
{
    double omega = 2.0 * M_PI * czestotliwosc;
    a = 2.0 * cos(omega); // sta³y wspó³czynnik
    n1 = _amplituda*sin(omega);     
    n2 = 0;
}

double SygnalSinusDekorator::generuj() {
    double base = dekorowanyGenerator.generuj();
    double xn = a * n1 - n2;
    n2 = n1;
    n1 = xn;
    return base + amplituda * xn;
}