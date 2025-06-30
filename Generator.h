#pragma once
#include <fstream>

/// <summary>
/// Abstrakcyjna klasa bazowa dla wszystkich generator�w sygna��w.
/// </summary>
class Generator
{
public:
    /// <summary>
    /// Wirtualny destruktor klasy Generator.
    /// Umo�liwia bezpieczne usuwanie obiekt�w pochodnych przez wska�nik do klasy bazowej.
    /// </summary>
    virtual ~Generator() = default;

    /// <summary>
    /// Generuje kolejn� pr�bk� sygna�u.
    /// </summary>
    /// <returns>Wygenerowana pr�bka jako liczba zmiennoprzecinkowa (double).</returns>
    virtual double generuj() = 0;

    virtual void serialize(std::ofstream& out) const = 0;
};