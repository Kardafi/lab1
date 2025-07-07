#pragma once
#include "Generator.h"

/// <summary>
/// Generator sta³ej wartoœci.
/// Zwraca tê sam¹ wartoœæ przy ka¿dym wywo³aniu metody generuj().
/// </summary>
class GeneratorStala : public Generator
{
private:
    /// <summary>
    /// Wartoœæ generowana przy ka¿dym wywo³aniu.
    /// </summary>
    double wartosc;

public:
    /// <summary>
    /// Konstruktor generatora sta³ej wartoœci.
    /// </summary>
    /// <param name="_wartosc">Wartoœæ, która bêdzie zwracana przy ka¿dym wywo³aniu. Domyœlnie 0.</param>
    GeneratorStala(double _wartosc = 0);

    /// <summary>
    /// Zwraca sta³¹ wartoœæ ustawion¹ w konstruktorze.
    /// </summary>
    /// <returns>Sta³a wartoœæ typu double.</returns>
    double generuj() override;

    /// <summary>
    /// Serializuje konfiguracjê generatora do strumienia wyjœciowego.
    /// </summary>
    /// <param name="out">Referencja do otwartego strumienia wyjœciowego (np. plikowego).</param>
    /// <remarks>
    /// Dane zapisywane s¹ w pseudo formacie JSON np:
    /// <code>
    /// {
    ///   "typ": "GeneratorStala",
    ///   "dane": {
    ///     "wartosc": 2.2
    ///   }
    /// }
    /// </code>
    /// </remarks>
    void serialize(std::ofstream& out) const override;
};
