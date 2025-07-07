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
    /// Cz�stotliwo�� sygna�u sinusoidalnego (Hz).
    /// </summary>
    double czestotliwosc;

    /// <summary>
    /// Cz�stotliwo�� k�towa omega (rad/s).
    /// </summary>
    double omega;

    /// <summary>
    /// Cz�stotliwo�� pr�bkowania (Hz).
    /// </summary>
    double probkowanie;

    /// <summary>
    /// Poprzednia warto�� pr�bki (n-1).
    /// </summary>
    double n1 = 0; // n-1

    /// <summary>
    /// Warto�� pr�bki sprzed dw�ch krok�w (n-2).
    /// </summary>
    double n2 = 0; // n-2

public:
    /// <summary>
    /// Konstruktor dekoratora generuj�cego sygna� sinusoidalny.
    /// </summary>
    /// <param name="generator">Referencja do dekorowanego generatora.</param>
    /// <param name="_amplituda">Amplituda sygna�u sinusoidalnego.</param>
    /// <param name="_czestotliwosc">Cz�stotliwo�� sygna�u sinusoidalnego (Hz).</param>
    /// <param name="_probkowanie">Cz�stotliwo�� pr�bkowania (Hz).</param>
    SygnalSinusDekorator(std::unique_ptr<Generator> _generator, double _amplituda, double _czestotliwosc, double _probkowanie);

    /// <summary>
    /// Generuje kolejn� pr�bk� sygna�u sinusoidalnego.
    /// </summary>
    /// <returns>Warto�� pr�bki sygna�u sinusoidalnego (double).</returns>
    double generuj() override;

    /// <summary>
    /// Serializuje dekorator do strumienia wyj�ciowego.
    /// </summary>
    /// <param name="out">Strumie� wyj�ciowy do zapisu.</param>
    void serialize(std::ofstream& out) const;
};