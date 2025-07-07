#include "SygnalSinusDekorator.h"
#include <cmath>

SygnalSinusDekorator::SygnalSinusDekorator(std::unique_ptr<Generator> _generator, double _amplituda, double _czestotliwosc, double _probkowanie) : GeneratorDekorator(std::move(_generator)), amplituda(_amplituda), czestotliwosc(_czestotliwosc), probkowanie(_probkowanie)
{
	omega = 2.0 * M_PI * czestotliwosc / probkowanie;
	n1 = _amplituda * sin(omega);
	n2 = 0;
}

double SygnalSinusDekorator::generuj()
{
    double xn = 2 * cos(omega) * n1 - n2;
    n2 = n1;
    n1 = xn;
    return xn + GeneratorDekorator::generuj();
}

void SygnalSinusDekorator::serialize(std::ofstream& out) const {
    dekorowanyGenerator->serialize(out);
    out << "{\n";
    out << "  \"typ\": \"SygnalSinusoidalny\",\n";
    out << "  \"dane\": {\n";
    out << "    \"amplituda\": " << amplituda << ",\n";
    out << "    \"czestotliwosc\": " << czestotliwosc << ",\n";
    out << "    \"probkowanie\": " << probkowanie << "\n";
    out << "  }\n";
    out << "}\n";
}