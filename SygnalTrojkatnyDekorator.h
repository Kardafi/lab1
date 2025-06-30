#pragma once
#include "GeneratorDekorator.h"

/// <summary>
/// Dekorator generuj¹cy sygna³ trójk¹tny.
/// Generuje sygna³ o zadanej amplitudzie i okresie.
/// </summary>
class SygnalTrojkatnyDekorator : public GeneratorDekorator
{
    /// <summary>
    /// Amplituda sygna³u trójk¹tnego.
    /// </summary>
    double amplituda;

    /// <summary>
    /// Okres sygna³u trójk¹tnego (liczba próbek).
    /// </summary>
    int okres;

    /// <summary>
    /// Licznik próbek (krok), który pozwala œledziæ pozycjê w okresie.
    /// </summary>
    int krok;

public:
    /// <summary>
    /// Konstruktor dekoratora generuj¹cego sygna³ trójk¹tny.
    /// </summary>
    /// <param name="generator">Referencja do dekorowanego generatora.</param>
    /// <param name="_amplituda">Amplituda sygna³u trójk¹tnego.</param>
    /// <param name="_okres">Okres sygna³u trójk¹tnego (liczba próbek).</param>
    SygnalTrojkatnyDekorator(Generator& generator, double _amplituda, int _okres);

    /// <summary>
    /// Generuje próbkê sygna³u trójk¹tnego.
    /// </summary>
    /// <returns>Wartoœæ próbki sygna³u trójk¹tnego.</returns>
    double generuj() override;

    void serialize(std::ofstream& out) const;
};
