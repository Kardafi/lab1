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
    /// <param name="_generator">WskaŸnik do dekorowanego generatora sygna³u.</param>
    /// <param name="_wartoscMaksymalna">Wartoœæ, do której ograniczana jest amplituda.</param>
    OgraniczenieAmplitudyDekorator(std::unique_ptr<Generator> _generator, double _wartoscMaksymalna);

    /// <summary>
    /// Generuje próbkê sygna³u z ograniczon¹ amplitud¹.
    /// </summary>
    /// <returns>Wartoœæ próbki po ograniczeniu do maksymalnej wartoœci.</returns>
    double generuj() override;

    /// <summary>
    /// Zapisuje konfiguracjê dekoratora do pliku wyjœciowego.
    /// </summary>
    /// <param name="out">Strumieñ wyjœciowy do którego zostanie zapisana konfiguracja.</param>
    void serialize(std::ofstream& out) const override;
};
