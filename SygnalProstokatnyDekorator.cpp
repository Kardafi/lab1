#include "SygnalProstokatnyDekorator.h"
#include <cmath>

SygnalProstokatnyDekorator::SygnalProstokatnyDekorator(std::unique_ptr<Generator> _generator, double _amplituda, int _okres, double _wypelnienie) : GeneratorDekorator(std::move(_generator)), amplituda(_amplituda), okres(_okres), wypelnienie(_wypelnienie)
{
}

double SygnalProstokatnyDekorator::generuj() {
    double czas_w_okresie = std::fmod(krok, okres);
    double wartosc = (czas_w_okresie < (okres * wypelnienie)) ? amplituda : 0.0;
    krok= (krok +1 % okres); //todo czy tak moze byc?

    return wartosc + GeneratorDekorator::generuj();
}

void SygnalProstokatnyDekorator::serialize(std::ofstream& out) const {
    dekorowanyGenerator->serialize(out);
    out << "{\n";
    out << "  \"typ\": \"SygnalProstokatny\",\n";
    out << "  \"dane\": {\n";
    out << "    \"amplituda\": " << amplituda << ",\n";
    out << "    \"okres\": " << okres << ",\n";
    out << "    \"wypelnienie\": " << wypelnienie << "\n";
    out << "  }\n";
    out << "}\n";
}
