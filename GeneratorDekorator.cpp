#include "GeneratorDekorator.h"

GeneratorDekorator::GeneratorDekorator(Generator& _generator)
	: dekorowanyGenerator(_generator)
{
}

double GeneratorDekorator::generuj()
{
	return dekorowanyGenerator.generuj();
}

