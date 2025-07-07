#pragma once
#include "Komponent.h"
#include "ModelARX.h"

/// <summary>
/// Komponent opakowuj¹cy model ARX, zgodny z interfejsem <c>Komponent</c>.
/// Umo¿liwia wykorzystanie modelu ARX w strukturze kompozytowej (Composite).
/// </summary>
class ModelARXKomponent : public Komponent
{
private:
    /// <summary>
    /// Obiekt modelu ARX u¿ywany do symulacji.
    /// </summary>
    ModelARX model;

public:
    /// <summary>
    /// Tworzy komponent ARX na podstawie przekazanego modelu.
    /// </summary>
    /// <param name="model">Model ARX, który ma zostaæ opakowany w komponent.</param>
    ModelARXKomponent(const ModelARX& model);

    /// <summary>
    /// Symuluje dzia³anie komponentu, wykorzystuj¹c opakowany model ARX.
    /// </summary>
    /// <param name="wejscie">Wartoœæ wejœciowa sygna³u.</param>
    /// <returns>Wartoœæ wyjœciowa po przetworzeniu przez model ARX.</returns>
    double symuluj(double wejscie) override;
};

