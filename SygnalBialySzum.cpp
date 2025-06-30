#include "SygnalBialySzum.h"

SygnalBialySzum::SygnalBialySzum(Generator& generator, double _amplituda) : GeneratorDekorator(generator), amplituda(_amplituda), rozklad(-amplituda, amplituda)
{
}

double SygnalBialySzum::generuj()
{
	double szum = rozklad(random_engine); // Generowanie szumu bia³ego
	return szum + GeneratorDekorator::generuj();
}

void SygnalBialySzum::serialize(std::ofstream& out) const {
    out << "{\n";
    out << "  \"typ\": \"SygnalBialySzum\",\n";
    out << "  \"dane\": {\n";
    out << "    \"amplituda\": " << amplituda << "\n";
    out << "  }\n";
    out << "}\n";
}