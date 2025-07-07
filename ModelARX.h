#pragma once
#include "ObiektSISO.h"
#include <vector>
#include <deque>
#include <random>
#include <iostream>

/// <summary>
/// Klasa reprezentuj�ca dyskretny model ARX, dziedzicz�ca po abstrakcyjnym obiekcie SISO.
/// 
/// Model opisuje zale�no�� sygna�u wyj�ciowego od wcze�niejszych warto�ci wej�� i wyj��,
/// z uwzgl�dnieniem czasu op�nienia oraz opcjonalnym dodawaniem szumu.
/// </summary>
class ModelARX : public ObiektSISO {
private:
    /// <summary>Wsp�czynniki mianownika (A).</summary>
    std::vector<double> A;

    /// <summary>Wsp�czynniki licznika (B).</summary>
    std::vector<double> B;

    /// <summary>Pami�� wcze�niejszych warto�ci sygna�u wej�ciowego.</summary>
    std::deque<double> pamiecWejscie;

    /// <summary>Pami�� wcze�niejszych warto�ci sygna�u wyj�ciowego.</summary>
    std::deque<double> pamiecWyjscie;

    /// <summary>Op�nienie (ilo�� pr�bek op�nienia sygna�u wej�ciowego).</summary>
    unsigned int opoznienie;

    /// <summary>Moc dodawanego szumu.</summary>
    double mocSzumu;

    std::default_random_engine generator;
    std::normal_distribution<double>* rozkladSzumu;

    /// <summary>
    /// Dodaje losowy szum do sygna�u wyj�ciowego na podstawie ustalonej mocy szumu.
    /// </summary>
    /// <returns>Warto�� szumu typu <c>double</c>.</returns>
    double dodajSzum();

public:
    /// <summary>
    /// Konstruktor inicjalizuj�cy model na podstawie wsp�czynnik�w A, B, op�nienia i mocy szumu.
    /// </summary>
    /// <param name="_A">Wsp�czynniki A (mianownik).</param>
    /// <param name="_B">Wsp�czynniki B (licznik).</param>
    /// <param name="_k">Dyskretny czas op�nienia.</param>
    /// <param name="_mocSzumu">Moc szumu.</param>
    ModelARX(const std::vector<double>& _A, const std::vector<double>& _B, unsigned int _k, int _mocSzumu);

    /// <summary>
    /// Konstruktor inicjalizuj�cy model na podstawie danych zapisanych w pliku.
    /// </summary>
    /// <param name="sciezkaPliku">�cie�ka do pliku z danymi modelu.</param>
    ModelARX(const std::string& sciezkaPliku);

    /// <summary>
    /// Destruktor modelu ARX.
    /// </summary>
    ~ModelARX();

    /// <summary>
    /// Zapisuje parametry modelu ARX do pliku w formacie pseudo-JSON.
    /// </summary>
    /// <param name="filename">Nazwa pliku, do kt�rego zostan� zapisane parametry.</param>
    void ZapiszDoPlikuJSON(const std::string& filename) const;

    /// <summary>
    /// Symuluje odpowied� modelu na podstawie nowego wej�cia.
    /// </summary>
    /// <param name="wejscie">Nowa warto�� sygna�u wej�ciowego.</param>
    /// <returns>Wygenerowana warto�� sygna�u wyj�ciowego.</returns>
    double symuluj(double wejscie) override;

    /// <summary>
    /// Zapisuje dane modelu do strumienia wyj�ciowego.
    /// </summary>
    /// <param name="out">Strumie� wyj�ciowy, do kt�rego zostanie zapisany model.</param>
    void serialize(std::ofstream& out) const;

    /// <summary>
    /// Deserializuje model ARX z podanego strumienia wej�ciowego.
    /// </summary>
    /// <param name="in">Strumie� wej�ciowy z danymi modelu.</param>
    /// <returns>Wska�nik <c>shared_ptr</c> do utworzonego modelu ARX.</returns>
    static std::shared_ptr<ModelARX> deserialize(std::istream& in);
};