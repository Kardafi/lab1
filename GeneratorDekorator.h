#pragma once
#include "Generator.h"
class GeneratorDekorator : public Generator 
{
public:
	Generator& dekorowanyGenerator;

	GeneratorDekorator(Generator& _generator);
	
	double generuj() =0;
};

