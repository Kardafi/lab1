#include "SygnalTrojkatnyDekorator.h"

SygnalTrojkatnyDekorator::SygnalTrojkatnyDekorator(Generator& generator, double _amplituda, int _okres) : GeneratorDekorator(generator), amplituda(_amplituda), okres(_okres), krok(0)
{
}

double SygnalTrojkatnyDekorator::generuj()
{
	double wynik = 0.0;
	if (krok < okres / 2) {
		wynik = (2 * amplituda / okres) * krok;
	}
	else if (krok < okres) {
		wynik = (2 * amplituda / okres) * (okres - krok);
	}
	else {
		wynik = 0.0;
		krok = -1; // resetujemy krok po pe³nym cyklu
	}
	++krok;
	return wynik + GeneratorDekorator::generuj();;
}

