#include "GeneratorStala.h"

GeneratorStala::GeneratorStala(double _wartosc) : wartosc(_wartosc)
{
}

double GeneratorStala::generuj()
{
	return wartosc;
}

void GeneratorStala::serialize(std::ofstream& out) const {
    out << "{\n";
    out << "  \"typ\": \"GeneratorStala\",\n";
    out << "  \"dane\": {\n";
    out << "    \"wartosc\": " << wartosc << "\n";
    out << "  }\n";
    out << "}\n";
}