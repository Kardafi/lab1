#include "OgraniczenieAmplitudyDekorator.h"

OgraniczenieAmplitudyDekorator::OgraniczenieAmplitudyDekorator(Generator& generator, double _wartoscMaksymalna) : GeneratorDekorator(generator), wartoscMaksymalna(_wartoscMaksymalna)
{
}

double OgraniczenieAmplitudyDekorator::generuj()
{
	double wartosc = dekorowanyGenerator.generuj();
	if (wartosc > wartoscMaksymalna)
		return wartoscMaksymalna;
	else if (wartosc < -wartoscMaksymalna)
		return -wartoscMaksymalna;

	return wartosc;
}

void OgraniczenieAmplitudyDekorator::serialize(std::ofstream& out) const {
	out << "{\n";
	out << "  \"typ\": \"OgraniczenieAmplitudy\",\n";
	out << "  \"dane\": {\n";
	out << "    \"wartoscMaksymalna\": " << wartoscMaksymalna << "\n";
	out << "  }\n";
	out << "}\n";
}
