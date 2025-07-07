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
    /// <param name="_generator">Wska�nik do dekorowanego generatora sygna�u.</param>
    /// <param name="_wartoscMaksymalna">Warto��, do kt�rej ograniczana jest amplituda.</param>
    OgraniczenieAmplitudyDekorator(std::unique_ptr<Generator> _generator, double _wartoscMaksymalna);

    /// <summary>
    /// Generuje pr�bk� sygna�u z ograniczon� amplitud�.
    /// </summary>
    /// <returns>Warto�� pr�bki po ograniczeniu do maksymalnej warto�ci.</returns>
    double generuj() override;

    /// <summary>
    /// Zapisuje konfiguracj� dekoratora do pliku wyj�ciowego.
    /// </summary>
    /// <param name="out">Strumie� wyj�ciowy do kt�rego zostanie zapisana konfiguracja.</param>
    void serialize(std::ofstream& out) const override;
};
