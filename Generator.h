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

    /// <summary>
    /// Serializuje konfiguracjê generatora do strumienia wyjœciowego.
    /// Musi zostaæ zaimplementowana w klasach pochodnych.
    /// </summary>
    /// <param name="out">Referencja do otwartego strumienia wyjœciowego (np. pliku).</param>
    virtual void serialize(std::ofstream& out) const = 0;
};