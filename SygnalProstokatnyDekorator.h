#pragma once
#include "GeneratorDekorator.h"

/// <summary>
/// Dekorator generuj¹cy sygna³ prostok¹tny.
/// Tworzy sygna³ o zadanej amplitudzie, okresie i wype³nieniu.
/// </summary>
class SygnalProstokatnyDekorator : public GeneratorDekorator
{
private:
    /// <summary>
    /// Amplituda sygna³u prostok¹tnego.
    /// </summary>
    double amplituda;

    /// <summary>
    /// Wype³nienie sygna³u prostok¹tnego (0-1).
    /// </summary>
    double wypelnienie;

    /// <summary>
    /// Okres sygna³u prostok¹tnego (liczba próbek).
    /// </summary>
    int okres;

    /// <summary>
    /// Licznik próbek (krok), który pozwala œledziæ pozycjê w okresie.
    /// </summary>
    int krok = 0;

public:
    /// <summary>
    /// Konstruktor dekoratora generuj¹cego sygna³ prostok¹tny.
    /// </summary>
    /// <param name="generator">Referencja do dekorowanego generatora.</param>
    /// <param name="_amplituda">Amplituda sygna³u prostok¹tnego.</param>
    /// <param name="_okres">Okres sygna³u prostok¹tnego (liczba próbek).</param>
    /// <param name="_wypelnienie">Wype³nienie sygna³u prostok¹tnego (0-100%).</param>
    SygnalProstokatnyDekorator(Generator& generator, double _amplituda, int _okres, double _wypelnienie);

    /// <summary>
    /// Generuje próbkê sygna³u prostok¹tnego.
    /// </summary>
    /// <returns>Wartoœæ próbki sygna³u prostok¹tnego.</returns>
    double generuj() override;
};
