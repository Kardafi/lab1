#pragma once
#include "GeneratorDekorator.h"

/// <summary>
/// Dekorator ograniczaj�cy amplitud� sygna�u.
/// Obcina warto�ci generowane przez dekorowany generator do zadanego maksimum.
/// </summary>
class OgraniczenieAmplitudyDekorator : public GeneratorDekorator
{
    /// <summary>
    /// Maksymalna warto��, jak� mo�e przyj�� wygenerowany sygna�.
    /// </summary>
    double wartoscMaksymalna;

public:
    /// <summary>
    /// Konstruktor dekoratora ograniczaj�cego amplitud�.
    /// </summary>
    /// <param name="generator">Referencja do dekorowanego generatora.</param>
    /// <param name="_wartoscMaksymalna">Warto��, do kt�rej ograniczana jest amplituda.</param>
    OgraniczenieAmplitudyDekorator(Generator& generator, double _wartoscMaksymalna);

    /// <summary>
    /// Generuje pr�bk� sygna�u z ograniczon� amplitud�.
    /// </summary>
    /// <returns>Warto�� pr�bki po ograniczeniu do maksimum.</returns>
    double generuj() override;

    void serialize(std::ofstream& out) const;
        
};
