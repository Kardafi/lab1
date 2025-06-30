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

    void serialize(std::ofstream& out) const override;
};
