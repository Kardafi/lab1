#pragma once
#include "GeneratorDekorator.h"

/// <summary>
/// Dekorator generuj�cy sygna� tr�jk�tny.
/// Generuje sygna� o zadanej amplitudzie i okresie.
/// </summary>
class SygnalTrojkatnyDekorator : public GeneratorDekorator
{
    /// <summary>
    /// Amplituda sygna�u tr�jk�tnego.
    /// </summary>
    double amplituda;

    /// <summary>
    /// Okres sygna�u tr�jk�tnego (liczba pr�bek).
    /// </summary>
    int okres;

    /// <summary>
    /// Licznik pr�bek (krok), kt�ry pozwala �ledzi� pozycj� w okresie.
    /// </summary>
    int krok;

public:
    /// <summary>
    /// Konstruktor dekoratora generuj�cego sygna� tr�jk�tny.
    /// </summary>
    /// <param name="generator">Unikalny wska�nik do dekorowanego generatora.</param>
    /// <param name="_amplituda">Amplituda sygna�u tr�jk�tnego.</param>
    /// <param name="_okres">Okres sygna�u tr�jk�tnego w liczbie pr�bek.</param>
    SygnalTrojkatnyDekorator(std::unique_ptr<Generator> _generator, double _amplituda, int _okres);

    /// <summary>
    /// Generuje kolejn� pr�bk� sygna�u tr�jk�tnego.
    /// </summary>
    /// <returns>Warto�� pr�bki sygna�u tr�jk�tnego (double).</returns>
    double generuj() override;

    /// <summary>
    /// Serializuje dekorator do podanego strumienia wyj�ciowego.
    /// </summary>
    /// <param name="out">Strumie� wyj�ciowy do zapisu.</param>
    void serialize(std::ofstream& out) const;
};
