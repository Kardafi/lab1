#pragma once
#include "GeneratorDekorator.h"
#include <random>

/// <summary>
/// Dekorator dodaj¹cy bia³y szum do sygna³u.
/// Szum generowany jest na podstawie rozk³adu jednostajnego w zakresie [-amplituda, amplituda].
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
    /// Rozk³ad jednostajny dla szumu.
    /// </summary>
    std::uniform_real_distribution<double> rozklad;

public:
    /// <summary>
    /// Konstruktor dekoratora dodaj¹cego bia³y szum.
    /// </summary>
    /// <param name="generator">Referencja do dekorowanego generatora.</param>
    /// <param name="_amplituda">Maksymalna amplituda szumu.</param>
    SygnalBialySzum(Generator& generator, double _amplituda);

    /// <summary>
    /// Generuje próbkê sygna³u z dodanym bia³ym szumem.
    /// </summary>
    /// <returns>Wartoœæ próbki z szumem.</returns>
    double generuj() override;

    void serialize(std::ofstream& out) const;
};
