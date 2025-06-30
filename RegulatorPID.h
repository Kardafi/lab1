#pragma once
#include "ObiektSISO.h"
#include <vector>
#include <deque>
#include <iostream>
#include <sstream>

/// <summary>
/// Klasa reprezentuj¹ca regulator PID (Proporcjonalno-Ca³kuj¹co-Ró¿niczkuj¹cy),
/// dziedzicz¹ca po abstrakcyjnej klasie ObiektSISO.
/// 
/// Regulator przetwarza sygna³ wejœciowy (uchyb) na podstawie sk³adników P, I i D,
/// generuj¹c odpowiedŸ steruj¹c¹.
/// </summary>
class RegulatorPID :
    public ObiektSISO
{
    double k; //wzmocnienie
    double Ti; //czas calkowania
    double Td; //czas rozniczkowania
    std::vector<double> pamiecUchyl; //pamieæ sygna³ów wejœciowych

public:
    /// <summary>
    /// Konstruktor tworz¹cy regulator z tylko wzmocnieniem proporcjonalnym.
    /// </summary>
    /// param name="_k">Wzmocnienie.</param>
    RegulatorPID(double _k);

    /// <summary>
    /// Konstruktor tworz¹cy regulator PI (Proporcjonalno-Ca³kuj¹cy).
    /// </summary>
	/// param name="_k">Wzmocnienie.</param>
	/// param name="_Ti">Czas ca³kowania.</param>
    RegulatorPID(double _k, double _Ti);

    /// <summary>
    /// Konstruktor tworz¹cy regulator PID (Proporcjonalno-Ca³kuj¹co-Ró¿niczkuj¹cy).
    /// </summary>
	/// param name="_k">Wzmocnienie.</param>
	/// param name="_Ti">Czas ca³kowania.</param>
	/// param name="_Td">Czas ró¿niczkowania.</param>
    RegulatorPID(double _k, double _Ti, double _Td);

    ~RegulatorPID();

    /// <summary>
    /// Symuluje odpowiedŸ regulatora na podstawie aktualnego uchybu.
    /// </summary>
    /// <param name="wejscie">Aktualny uchyb (ró¿nica miêdzy wartoœci¹ zadan¹ a rzeczywist¹).</param>
    /// <returns>Wartoœæ sygna³u steruj¹cego wygenerowana przez regulator.</returns>
    double symuluj(double wejscie) override;

    /// <summary>
    /// Ustawia nowe wzmocnienie proporcjonalne.
    /// </summary>
	/// param name="_k">Nowe wzmocnienie.</param>
    void setK(double _k);
    /// <summary>
    /// Ustawia nowy czas ca³kowania.
    /// </summary>
	/// param name="_Ti">Nowy czas ca³kowania.</param>
    void setTi(double _Ti);
    /// <summary>
    /// Ustawia nowy czas ró¿niczkowania.
    /// </summary>
	/// param name="_Td">Nowy czas ró¿niczkowania.</param>
    void setTd(double _Td);

    void serialize(std::ostream& out) const;

    static std::shared_ptr<RegulatorPID> deserialize(std::istream& in);


private:
    /// <summary>
    /// Sprawdza poprawnoœæ wartoœci nastawy (czy jest dodatnia).
    /// </summary>
    /// <param name="_nastawa">Wartoœæ nastawy do sprawdzenia.</param>
    /// <returns>Zwraca 1 jeœli poprawna, w przeciwnym wypadku 0.</returns>
    int SprawdzNastawe(double _nastawa);
};

