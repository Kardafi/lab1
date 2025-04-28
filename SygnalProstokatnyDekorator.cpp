#include "SygnalProstokatnyDekorator.h"
#include <cmath>

SygnalProstokatnyDekorator::SygnalProstokatnyDekorator(Generator& generator, double _amplituda, double _czestotliwosc, double _wypelnienie) 
	: GeneratorDekorator(generator), amplituda(_amplituda), czestotliwosc(_czestotliwosc), wypelnienie(_wypelnienie), czas(0.0) 
{ 
}

double SygnalProstokatnyDekorator::generuj() {
    double base = dekorowanyGenerator.generuj();


    double okres = 1.0 / czestotliwosc;
    double czas_w_okresie = fmod(czas, okres);
    double wartosc = (czas_w_okresie < okres * (wypelnienie / 100.0)) ? amplituda : 0;
    czas += 0.01; // przyk³adowy krok czasu
    return base + wartosc;
}
