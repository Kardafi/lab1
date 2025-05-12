#pragma once
#include "Komponent.h"
#include "ModelARX.h"

class ModelARXKomponent : public Komponent
{
private:
    ModelARX model;

public:
    /// <summary>
    /// Tworzy komponent ARX na podstawie konkretnego modelu.
    /// </summary>
    /// <param name="model">Model ARX do opakowania.</param>
    ModelARXKomponent(const ModelARX& model);

    /// <summary>
    /// Symuluje model ARX.
    /// </summary>
    double symuluj(double wejscie) override;

};

