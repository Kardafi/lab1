#include "SygnalProstokatnyDekorator.h"
#include <cmath>

SygnalProstokatnyDekorator::SygnalProstokatnyDekorator(Generator& generator, double _amplituda, int _okres, double _wypelnienie)
	: GeneratorDekorator(generator), amplituda(_amplituda), okres(_okres), wypelnienie(_wypelnienie) 
{ 
}

double SygnalProstokatnyDekorator::generuj() {
    double czas_w_okresie = std::fmod(krok, okres);
    double wartosc = (czas_w_okresie < (okres * wypelnienie)) ? amplituda : 0.0;
    krok++; 

    return wartosc + GeneratorDekorator::generuj();
}
