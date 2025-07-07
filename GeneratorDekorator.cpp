#include "GeneratorDekorator.h"

GeneratorDekorator::GeneratorDekorator(std::unique_ptr<Generator> _generator) : dekorowanyGenerator(std::move(_generator)) {
}

double GeneratorDekorator::generuj()
{
	return dekorowanyGenerator->generuj();
}

