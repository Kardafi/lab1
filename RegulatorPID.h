#pragma once
#include "ObiektSISO.h"
#include <vector>
#include <deque>
#include <iostream>
#include <sstream>

/// <summary>
/// Klasa reprezentuj�ca regulator PID (Proporcjonalno-Ca�kuj�co-R�niczkuj�cy),
/// dziedzicz�ca po abstrakcyjnej klasie ObiektSISO.
/// 
/// Regulator przetwarza sygna� wej�ciowy (uchyb) na podstawie sk�adnik�w P, I i D,
/// generuj�c odpowied� steruj�c�.
/// </summary>
class RegulatorPID : public ObiektSISO
{
    double k; ///< Wzmocnienie proporcjonalne
    double Ti; ///< Czas ca�kowania
    double Td; ///< Czas r�niczkowania
    std::vector<double> pamiecUchyl; ///< Pami�� sygna��w wej�ciowych (uchyb�w)

public:
    /// <summary>
    /// Konstruktor tworz�cy regulator z tylko wzmocnieniem proporcjonalnym.
    /// </summary>
    /// <param name="_k">Wzmocnienie proporcjonalne.</param>
    RegulatorPID(double _k);

    /// <summary>
    /// Konstruktor tworz�cy regulator PI (Proporcjonalno-Ca�kuj�cy).
    /// </summary>
    /// <param name="_k">Wzmocnienie proporcjonalne.</param>
    /// <param name="_Ti">Czas ca�kowania.</param>
    RegulatorPID(double _k, double _Ti);

    /// <summary>
    /// Konstruktor tworz�cy regulator PID (Proporcjonalno-Ca�kuj�co-R�niczkuj�cy).
    /// </summary>
    /// <param name="_k">Wzmocnienie proporcjonalne.</param>
    /// <param name="_Ti">Czas ca�kowania.</param>
    /// <param name="_Td">Czas r�niczkowania.</param>
    RegulatorPID(double _k, double _Ti, double _Td);

    /// <summary>
    /// Destruktor klasy RegulatorPID.
    /// </summary>
    ~RegulatorPID();

    /// <summary>
    /// Symuluje odpowied� regulatora na podstawie aktualnego uchybu.
    /// </summary>
    /// <param name="wejscie">Aktualny uchyb (r�nica mi�dzy warto�ci� zadan� a rzeczywist�).</param>
    /// <returns>Warto�� sygna�u steruj�cego wygenerowana przez regulator.</returns>
    double symuluj(double wejscie) override;

    /// <summary>
    /// Ustawia nowe wzmocnienie proporcjonalne.
    /// </summary>
    /// <param name="_k">Nowe wzmocnienie proporcjonalne.</param>
    void setK(double _k);

    /// <summary>
    /// Ustawia nowy czas ca�kowania.
    /// </summary>
    /// <param name="_Ti">Nowy czas ca�kowania.</param>
    void setTi(double _Ti);

    /// <summary>
    /// Ustawia nowy czas r�niczkowania.
    /// </summary>
    /// <param name="_Td">Nowy czas r�niczkowania.</param>
    void setTd(double _Td);

    /// <summary>
    /// Serializuje obiekt regulatora do strumienia wyj�ciowego.
    /// </summary>
    /// <param name="out">Strumie� wyj�ciowy do zapisu danych.</param>
    void serialize(std::ostream& out) const;

    /// <summary>
    /// Deserializuje obiekt regulatora z podanego strumienia wej�ciowego.
    /// </summary>
    /// <param name="in">Strumie� wej�ciowy zawieraj�cy dane do odczytu.</param>
    /// <returns>Wska�nik do nowo utworzonego obiektu RegulatorPID.</returns>
    static std::shared_ptr<RegulatorPID> deserialize(std::istream& in);

private:
    /// <summary>
    /// Sprawdza poprawno�� warto�ci nastawy (czy jest dodatnia).
    /// </summary>
    /// <param name="_nastawa">Warto�� nastawy do sprawdzenia.</param>
    /// <returns>Zwraca 1 je�li warto�� jest poprawna (dodatnia), w przeciwnym wypadku 0.</returns>
    int SprawdzNastawe(double _nastawa);
};

