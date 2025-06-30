#pragma once
#include "GeneratorDekorator.h"

/// <summary>
/// Dekorator ograniczaj¹cy amplitudê sygna³u.
/// Obcina wartoœci generowane przez dekorowany generator do zadanego maksimum.
/// </summary>
class OgraniczenieAmplitudyDekorator : public GeneratorDekorator
{
    /// <summary>
    /// Maksymalna wartoœæ, jak¹ mo¿e przyj¹æ wygenerowany sygna³.
    /// </summary>
    double wartoscMaksymalna;

public:
    /// <summary>
    /// Konstruktor dekoratora ograniczaj¹cego amplitudê.
    /// </summary>
    /// <param name="generator">Referencja do dekorowanego generatora.</param>
    /// <param name="_wartoscMaksymalna">Wartoœæ, do której ograniczana jest amplituda.</param>
    OgraniczenieAmplitudyDekorator(Generator& generator, double _wartoscMaksymalna);

    /// <summary>
    /// Generuje próbkê sygna³u z ograniczon¹ amplitud¹.
    /// </summary>
    /// <returns>Wartoœæ próbki po ograniczeniu do maksimum.</returns>
    double generuj() override;

    void serialize(std::ofstream& out) const;
        
};
