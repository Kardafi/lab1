#pragma once
#include "Generator.h"

/// <summary>
/// Klasa bazowa dla dekorator�w generator�w sygna��w.
/// Umo�liwia rozszerzanie dzia�ania innych generator�w przy u�yciu wzorca Dekorator.
/// </summary>
class GeneratorDekorator : public Generator
{
public:
    /// <summary>
    /// Wska�nik do dekorowanego generatora.
    /// </summary>
    std::unique_ptr<Generator> dekorowanyGenerator;

    /// <summary>
    /// Konstruktor dekoratora generatora.
    /// </summary>
    /// <param name="_generator">Wska�nik do generatora, kt�ry ma by� dekorowany.</param>
    GeneratorDekorator(std::unique_ptr<Generator> _generator);

    /// <summary>
    /// Generuje pr�bk� sygna�u z rozszerzon� funkcjonalno�ci�.
    /// </summary>
    /// <returns>Wygenerowana pr�bka jako liczba zmiennoprzecinkowa (double).</returns>
    virtual double generuj() = 0;
};
