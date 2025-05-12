#include "ModelARXKomponent.h"

ModelARXKomponent::ModelARXKomponent(const ModelARX& model) : model(model)
{
}

double ModelARXKomponent::symuluj(double wejscie)
{
	return model.symuluj(wejscie);
}
