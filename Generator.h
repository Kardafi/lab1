#pragma once
#include <fstream>

/// <summary>
/// Abstrakcyjna klasa bazowa dla wszystkich generatorów sygna³ów.
/// </summary>
class Generator
{
public:
    /// <summary>
    /// Wirtualny destruktor klasy Generator.
    /// Umo¿liwia bezpieczne usuwanie obiektów pochodnych przez wskaŸnik do klasy bazowej.
    /// </summary>
    virtual ~Generator() = default;

    /// <summary>
    /// Generuje kolejn¹ próbkê sygna³u.
    /// </summary>
    /// <returns>Wygenerowana próbka jako liczba zmiennoprzecinkowa (double).</returns>
    virtual double generuj() = 0;

    virtual void serialize(std::ofstream& out) const = 0;
};