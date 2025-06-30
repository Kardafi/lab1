#pragma once
#include "GeneratorDekorator.h"

constexpr auto M_PI = 3.14159265358979323846;

/// <summary>
/// Dekorator generuj�cy sygna� sinusoidalny.
/// Wygenerowany sygna� ma okre�lon� amplitud�, cz�stotliwo�� i pr�bkowanie.
/// </summary>
class SygnalSinusDekorator : public GeneratorDekorator
{
    /// <summary>
    /// Amplituda sygna�u sinusoidalnego.
    /// </summary>
    double amplituda;

    /// <summary>
    /// Cz�stotliwo�� sygna�u sinusoidalnego.
    /// </summary>
    double czestotliwosc;

    /// <summary>
    /// Cz�stotliwo�� k�ta omega.
    /// </summary>
    double omega;

    /// <summary>
    /// Cz�stotliwo�� pr�bkowania.
    /// </summary>
    double probkowanie;

    /// <summary>
    /// Zmienna pomocnicza przechowuj�ca warto�� n-1.
    /// </summary>
    double n1 = 0; // n-1

    /// <summary>
    /// Zmienna pomocnicza przechowuj�ca warto�� n-2.
    /// </summary>
    double n2 = 0; // n-2

public:
    /// <summary>
    /// Konstruktor dekoratora generuj�cego sygna� sinusoidalny.
    /// </summary>
    /// <param name="generator">Referencja do dekorowanego generatora.</param>
    /// <param name="_amplituda">Amplituda sygna�u sinusoidalnego.</param>
    /// <param name="_czestotliwosc">Cz�stotliwo�� sygna�u sinusoidalnego (w Hz).</param>
    /// <param name="_probkowanie">Cz�stotliwo�� pr�bkowania (w Hz).</param>
    SygnalSinusDekorator(Generator& generator, double _amplituda, double _czestotliwosc, double _probkowanie);

    /// <summary>
    /// Generuje kolejn� pr�bk� sygna�u sinusoidalnego.
    /// </summary>
    /// <returns>Warto�� pr�bki sygna�u sinusoidalnego.</returns>
    double generuj() override;

    void serialize(std::ofstream& out) const;
};
