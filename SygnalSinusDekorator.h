#pragma once
#include "GeneratorDekorator.h"

constexpr auto M_PI = 3.14159265358979323846;

/// <summary>
/// Dekorator generuj¹cy sygna³ sinusoidalny.
/// Wygenerowany sygna³ ma okreœlon¹ amplitudê, czêstotliwoœæ i próbkowanie.
/// </summary>
class SygnalSinusDekorator : public GeneratorDekorator
{
    /// <summary>
    /// Amplituda sygna³u sinusoidalnego.
    /// </summary>
    double amplituda;

    /// <summary>
    /// Czêstotliwoœæ sygna³u sinusoidalnego.
    /// </summary>
    double czestotliwosc;

    /// <summary>
    /// Czêstotliwoœæ k¹ta omega.
    /// </summary>
    double omega;

    /// <summary>
    /// Czêstotliwoœæ próbkowania.
    /// </summary>
    double probkowanie;

    /// <summary>
    /// Zmienna pomocnicza przechowuj¹ca wartoœæ n-1.
    /// </summary>
    double n1 = 0; // n-1

    /// <summary>
    /// Zmienna pomocnicza przechowuj¹ca wartoœæ n-2.
    /// </summary>
    double n2 = 0; // n-2

public:
    /// <summary>
    /// Konstruktor dekoratora generuj¹cego sygna³ sinusoidalny.
    /// </summary>
    /// <param name="generator">Referencja do dekorowanego generatora.</param>
    /// <param name="_amplituda">Amplituda sygna³u sinusoidalnego.</param>
    /// <param name="_czestotliwosc">Czêstotliwoœæ sygna³u sinusoidalnego (w Hz).</param>
    /// <param name="_probkowanie">Czêstotliwoœæ próbkowania (w Hz).</param>
    SygnalSinusDekorator(Generator& generator, double _amplituda, double _czestotliwosc, double _probkowanie);

    /// <summary>
    /// Generuje kolejn¹ próbkê sygna³u sinusoidalnego.
    /// </summary>
    /// <returns>Wartoœæ próbki sygna³u sinusoidalnego.</returns>
    double generuj() override;

    void serialize(std::ofstream& out) const;
};
