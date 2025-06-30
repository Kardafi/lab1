#pragma once
#include "GeneratorDekorator.h"
#include <random>

/// <summary>
/// Dekorator dodaj�cy bia�y szum do sygna�u.
/// Szum generowany jest na podstawie rozk�adu jednostajnego w zakresie [-amplituda, amplituda].
/// </summary>
class SygnalBialySzum : public GeneratorDekorator
{
    /// <summary>
    /// Maksymalna amplituda dodawanego szumu.
    /// </summary>
    double amplituda;

    /// <summary>
    /// Generator liczb losowych.
    /// </summary>
    std::default_random_engine random_engine;

    /// <summary>
    /// Rozk�ad jednostajny dla szumu.
    /// </summary>
    std::uniform_real_distribution<double> rozklad;

public:
    /// <summary>
    /// Konstruktor dekoratora dodaj�cego bia�y szum.
    /// </summary>
    /// <param name="generator">Referencja do dekorowanego generatora.</param>
    /// <param name="_amplituda">Maksymalna amplituda szumu.</param>
    SygnalBialySzum(Generator& generator, double _amplituda);

    /// <summary>
    /// Generuje pr�bk� sygna�u z dodanym bia�ym szumem.
    /// </summary>
    /// <returns>Warto�� pr�bki z szumem.</returns>
    double generuj() override;

    void serialize(std::ofstream& out) const;
};
