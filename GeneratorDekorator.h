#pragma once
#include "Generator.h"

/// <summary>
/// Klasa bazowa dla dekoratorów generatorów sygna³ów.
/// Umo¿liwia rozszerzanie dzia³ania innych generatorów przy u¿yciu wzorca Dekorator.
/// </summary>
class GeneratorDekorator : public Generator
{
public:
    /// <summary>
    /// WskaŸnik do dekorowanego generatora.
    /// </summary>
    std::unique_ptr<Generator> dekorowanyGenerator;

    /// <summary>
    /// Konstruktor dekoratora generatora.
    /// </summary>
    /// <param name="_generator">WskaŸnik do generatora, który ma byæ dekorowany.</param>
    GeneratorDekorator(std::unique_ptr<Generator> _generator);

    /// <summary>
    /// Generuje próbkê sygna³u z rozszerzon¹ funkcjonalnoœci¹.
    /// </summary>
    /// <returns>Wygenerowana próbka jako liczba zmiennoprzecinkowa (double).</returns>
    virtual double generuj() = 0;
};
