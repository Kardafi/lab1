#pragma once
#include <memory>
#include <map>

#include "Generator.h"
#include "ModelARX.h"
#include "RegulatorPID.h"
#include "KompozytSzeregowy.h"
#include "GeneratorStala.h"
#include "SygnalTrojkatnyDekorator.h"
#include "SygnalBialySzum.h"
#include "SygnalProstokatnyDekorator.h"
#include "SygnalSinusDekorator.h"
#include "OgraniczenieAmplitudyDekorator.h"

/// <summary>
/// Klasa odpowiadaj�ca za interfejs konsolowy aplikacji.
/// Zarz�dza konfiguracj� sygna�u, modelem ARX i regulatorem PID,
/// umo�liwiaj�c ich edycj�, zapis/wczytanie oraz przeprowadzenie symulacji.
/// </summary>
class Interfejs
{
private:
    /// <summary>
    /// Wska�nik do aktualnie ustawionego generatora sygna�u (z dekoratorami).
    /// </summary>
    std::unique_ptr<Generator> sygnal;

    /// <summary>
    /// Model ARX symulowanego uk�adu.
    /// </summary>
    std::shared_ptr<ModelARX> modelARX;

    /// <summary>
    /// Regulator PID steruj�cy uk�adem.
    /// </summary>
    std::shared_ptr<RegulatorPID> regulatorPID;

    /// <summary>
    /// Pobiera wyb�r u�ytkownika z konsoli w zakresie od 1 do <paramref name="liczbaMax"/>.
    /// </summary>
    /// <param name="liczbaMax">Maksymalna liczba mo�liwego wyboru (domy�lnie 7).</param>
    /// <returns>Wybrana liczba typu <c>int</c>.</returns>
    int PobierzWyborUzytkownika(int liczbaMax = 7);

    /// <summary>
    /// Pobiera liczb� zmiennoprzecinkow� od u�ytkownika z wej�cia konsolowego.
    /// </summary>
    /// <returns>Liczba typu <c>double</c>.</returns>
    double PobierzLiczbeOdUzytkownika();

    /// <summary>
    /// Deserializuje sygna� (wraz z dekoratorami) ze strumienia wej�ciowego.
    /// </summary>
    /// <param name="in">Strumie� wej�ciowy (plikowy).</param>
    /// <returns>Unikalny wska�nik do zrekonstruowanego obiektu <c>Generator</c>.</returns>
    std::unique_ptr<Generator> DeserializujSygnal(std::ifstream& in);

    /// <summary>
    /// Deserializuje model ARX ze strumienia wej�ciowego.
    /// </summary>
    /// <param name="in">Strumie� wej�ciowy (plikowy).</param>
    /// <returns>Wsp�dzielony wska�nik do zrekonstruowanego obiektu <c>ModelARX</c>.</returns>
    std::shared_ptr<ModelARX> DeserializujModel(std::ifstream& in);

    /// <summary>
    /// Deserializuje regulator PID ze strumienia wej�ciowego.
    /// </summary>
    /// <param name="in">Strumie� wej�ciowy (plikowy).</param>
    /// <returns>Wsp�dzielony wska�nik do zrekonstruowanego obiektu <c>RegulatorPID</c>.</returns>
    std::shared_ptr<RegulatorPID> DeserializujRegulator(std::ifstream& in);

    /// <summary>
    /// Umo�liwia konfiguracj� sygna�u wej�ciowego.
    /// </summary>
    void UstawieniaSygnalu();

    /// <summary>
    /// Umo�liwia konfiguracj� modelu ARX.
    /// </summary>
    void UstawieniaModeluARX();

    /// <summary>
    /// Umo�liwia konfiguracj� regulatora PID.
    /// </summary>
    void UstawieniaRegulatoraPID();

    /// <summary>
    /// Uruchamia symulacj� uk�adu na podstawie skonfigurowanego sygna�u, modelu ARX i regulatora PID.
    /// </summary>
    void UruchomSymulacjeUkladu();

    /// <summary>
    /// Zapisuje aktualn� konfiguracj� sygna�u, modelu ARX i regulatora PID do pliku.
    /// </summary>
    void ZapiszKonfiguracjeDoPliku();

    /// <summary>
    /// Wczytuje konfiguracj� sygna�u, modelu ARX i regulatora PID z pliku.
    /// </summary>
    void WczytajKonfiguracjeZPliku();

    /// <summary>
    /// Wy�wietla menu g��wne programu i obs�uguje wybory u�ytkownika.
    /// </summary>
    void PokazMenu();

public:
    /// <summary>
    /// Uruchamia g��wny interfejs programu.
    /// </summary>
    void InterfejsStart();
};