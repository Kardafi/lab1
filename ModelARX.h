#pragma once
#include "ObiektSISO.h"
#include <vector>
#include <deque>
#include <random>
#include <iostream>

/// <summary>
/// Klasa reprezentuj¹ca dyskretny model ARX, dziedzicz¹ca po abstrakcyjnym obiekcie SISO.
/// 
/// Model opisuje zale¿noœæ sygna³u wyjœciowego od wczeœniejszych wartoœci wejœæ i wyjœæ,
/// z uwzglêdnieniem czasu opóŸnienia oraz opcjonalnym dodawaniem szumu.
/// </summary>
class ModelARX : public ObiektSISO {
private:
    /// <summary>Wspó³czynniki mianownika (A).</summary>
    std::vector<double> A;

    /// <summary>Wspó³czynniki licznika (B).</summary>
    std::vector<double> B;

    /// <summary>Pamiêæ wczeœniejszych wartoœci sygna³u wejœciowego.</summary>
    std::deque<double> pamiecWejscie;

    /// <summary>Pamiêæ wczeœniejszych wartoœci sygna³u wyjœciowego.</summary>
    std::deque<double> pamiecWyjscie;

    /// <summary>OpóŸnienie (iloœæ próbek opóŸnienia sygna³u wejœciowego).</summary>
    unsigned int opoznienie;

    /// <summary>Moc dodawanego szumu.</summary>
    double mocSzumu;

    std::default_random_engine generator;
    std::normal_distribution<double>* rozkladSzumu;

    /// <summary>
    /// Dodaje losowy szum do sygna³u wyjœciowego na podstawie ustalonej mocy szumu.
    /// </summary>
    /// <returns>Wartoœæ szumu typu <c>double</c>.</returns>
    double dodajSzum();

public:
    /// <summary>
    /// Konstruktor inicjalizuj¹cy model na podstawie wspó³czynników A, B, opóŸnienia i mocy szumu.
    /// </summary>
    /// <param name="_A">Wspó³czynniki A (mianownik).</param>
    /// <param name="_B">Wspó³czynniki B (licznik).</param>
    /// <param name="_k">Dyskretny czas opóŸnienia.</param>
    /// <param name="_mocSzumu">Moc szumu.</param>
    ModelARX(const std::vector<double>& _A, const std::vector<double>& _B, unsigned int _k, int _mocSzumu);

    /// <summary>
    /// Konstruktor inicjalizuj¹cy model na podstawie danych zapisanych w pliku.
    /// </summary>
    /// <param name="sciezkaPliku">Œcie¿ka do pliku z danymi modelu.</param>
    ModelARX(const std::string& sciezkaPliku);

    /// <summary>
    /// Destruktor modelu ARX.
    /// </summary>
    ~ModelARX();

    /// <summary>
    /// Zapisuje parametry modelu ARX do pliku w formacie pseudo-JSON.
    /// </summary>
    /// <param name="filename">Nazwa pliku, do którego zostan¹ zapisane parametry.</param>
    void ZapiszDoPlikuJSON(const std::string& filename) const;

    /// <summary>
    /// Symuluje odpowiedŸ modelu na podstawie nowego wejœcia.
    /// </summary>
    /// <param name="wejscie">Nowa wartoœæ sygna³u wejœciowego.</param>
    /// <returns>Wygenerowana wartoœæ sygna³u wyjœciowego.</returns>
    double symuluj(double wejscie) override;

    /// <summary>
    /// Zapisuje dane modelu do strumienia wyjœciowego.
    /// </summary>
    /// <param name="out">Strumieñ wyjœciowy, do którego zostanie zapisany model.</param>
    void serialize(std::ofstream& out) const;

    /// <summary>
    /// Deserializuje model ARX z podanego strumienia wejœciowego.
    /// </summary>
    /// <param name="in">Strumieñ wejœciowy z danymi modelu.</param>
    /// <returns>WskaŸnik <c>shared_ptr</c> do utworzonego modelu ARX.</returns>
    static std::shared_ptr<ModelARX> deserialize(std::istream& in);
};