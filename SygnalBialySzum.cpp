#include "SygnalBialySzum.h"

SygnalBialySzum::SygnalBialySzum(Generator& generator, double _amplituda) : GeneratorDekorator(generator), amplituda(_amplituda), rozklad(-amplituda, amplituda)
{
}

double SygnalBialySzum::generuj()
{
	double szum = rozklad(random_engine); // Generowanie szumu bia³ego
	return szum + GeneratorDekorator::generuj();
}

