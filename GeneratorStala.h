#pragma once
#include "Generator.h"

/// <summary>
/// Generator sta�ej warto�ci.
/// Zwraca t� sam� warto�� przy ka�dym wywo�aniu metody generuj().
/// </summary>
class GeneratorStala : public Generator
{
private:
    /// <summary>
    /// Warto�� generowana przy ka�dym wywo�aniu.
    /// </summary>
    double wartosc;

public:
    /// <summary>
    /// Konstruktor generatora sta�ej warto�ci.
    /// </summary>
    /// <param name="_wartosc">Warto��, kt�ra b�dzie zwracana przy ka�dym wywo�aniu. Domy�lnie 0.</param>
    GeneratorStala(double _wartosc = 0);

    /// <summary>
    /// Zwraca sta�� warto�� ustawion� w konstruktorze.
    /// </summary>
    /// <returns>Sta�a warto�� typu double.</returns>
    double generuj() override;

    /// <summary>
    /// Serializuje konfiguracj� generatora do strumienia wyj�ciowego.
    /// </summary>
    /// <param name="out">Referencja do otwartego strumienia wyj�ciowego (np. plikowego).</param>
    /// <remarks>
    /// Dane zapisywane s� w pseudo formacie JSON np:
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
