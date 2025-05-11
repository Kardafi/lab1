#pragma once
#include "GeneratorDekorator.h"

/// <summary>
/// Dekorator generuj�cy sygna� prostok�tny.
/// Tworzy sygna� o zadanej amplitudzie, okresie i wype�nieniu.
/// </summary>
class SygnalProstokatnyDekorator : public GeneratorDekorator
{
private:
    /// <summary>
    /// Amplituda sygna�u prostok�tnego.
    /// </summary>
    double amplituda;

    /// <summary>
    /// Wype�nienie sygna�u prostok�tnego (0-1).
    /// </summary>
    double wypelnienie;

    /// <summary>
    /// Okres sygna�u prostok�tnego (liczba pr�bek).
    /// </summary>
    int okres;

    /// <summary>
    /// Licznik pr�bek (krok), kt�ry pozwala �ledzi� pozycj� w okresie.
    /// </summary>
    int krok = 0;

public:
    /// <summary>
    /// Konstruktor dekoratora generuj�cego sygna� prostok�tny.
    /// </summary>
    /// <param name="generator">Referencja do dekorowanego generatora.</param>
    /// <param name="_amplituda">Amplituda sygna�u prostok�tnego.</param>
    /// <param name="_okres">Okres sygna�u prostok�tnego (liczba pr�bek).</param>
    /// <param name="_wypelnienie">Wype�nienie sygna�u prostok�tnego (0-100%).</param>
    SygnalProstokatnyDekorator(Generator& generator, double _amplituda, int _okres, double _wypelnienie);

    /// <summary>
    /// Generuje pr�bk� sygna�u prostok�tnego.
    /// </summary>
    /// <returns>Warto�� pr�bki sygna�u prostok�tnego.</returns>
    double generuj() override;
};
