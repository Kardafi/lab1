#pragma once
#include "Komponent.h"
#include "ModelARX.h"

/// <summary>
/// Komponent opakowuj�cy model ARX, zgodny z interfejsem <c>Komponent</c>.
/// Umo�liwia wykorzystanie modelu ARX w strukturze kompozytowej (Composite).
/// </summary>
class ModelARXKomponent : public Komponent
{
private:
    /// <summary>
    /// Obiekt modelu ARX u�ywany do symulacji.
    /// </summary>
    ModelARX model;

public:
    /// <summary>
    /// Tworzy komponent ARX na podstawie przekazanego modelu.
    /// </summary>
    /// <param name="model">Model ARX, kt�ry ma zosta� opakowany w komponent.</param>
    ModelARXKomponent(const ModelARX& model);

    /// <summary>
    /// Symuluje dzia�anie komponentu, wykorzystuj�c opakowany model ARX.
    /// </summary>
    /// <param name="wejscie">Warto�� wej�ciowa sygna�u.</param>
    /// <returns>Warto�� wyj�ciowa po przetworzeniu przez model ARX.</returns>
    double symuluj(double wejscie) override;
};

