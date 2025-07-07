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
/// Klasa odpowiadaj¹ca za interfejs konsolowy aplikacji.
/// Zarz¹dza konfiguracj¹ sygna³u, modelem ARX i regulatorem PID,
/// umo¿liwiaj¹c ich edycjê, zapis/wczytanie oraz przeprowadzenie symulacji.
/// </summary>
class Interfejs
{
private:
    /// <summary>
    /// WskaŸnik do aktualnie ustawionego generatora sygna³u (z dekoratorami).
    /// </summary>
    std::unique_ptr<Generator> sygnal;

    /// <summary>
    /// Model ARX symulowanego uk³adu.
    /// </summary>
    std::shared_ptr<ModelARX> modelARX;

    /// <summary>
    /// Regulator PID steruj¹cy uk³adem.
    /// </summary>
    std::shared_ptr<RegulatorPID> regulatorPID;

    /// <summary>
    /// Pobiera wybór u¿ytkownika z konsoli w zakresie od 1 do <paramref name="liczbaMax"/>.
    /// </summary>
    /// <param name="liczbaMax">Maksymalna liczba mo¿liwego wyboru (domyœlnie 7).</param>
    /// <returns>Wybrana liczba typu <c>int</c>.</returns>
    int PobierzWyborUzytkownika(int liczbaMax = 7);

    /// <summary>
    /// Pobiera liczbê zmiennoprzecinkow¹ od u¿ytkownika z wejœcia konsolowego.
    /// </summary>
    /// <returns>Liczba typu <c>double</c>.</returns>
    double PobierzLiczbeOdUzytkownika();

    /// <summary>
    /// Deserializuje sygna³ (wraz z dekoratorami) ze strumienia wejœciowego.
    /// </summary>
    /// <param name="in">Strumieñ wejœciowy (plikowy).</param>
    /// <returns>Unikalny wskaŸnik do zrekonstruowanego obiektu <c>Generator</c>.</returns>
    std::unique_ptr<Generator> DeserializujSygnal(std::ifstream& in);

    /// <summary>
    /// Deserializuje model ARX ze strumienia wejœciowego.
    /// </summary>
    /// <param name="in">Strumieñ wejœciowy (plikowy).</param>
    /// <returns>Wspó³dzielony wskaŸnik do zrekonstruowanego obiektu <c>ModelARX</c>.</returns>
    std::shared_ptr<ModelARX> DeserializujModel(std::ifstream& in);

    /// <summary>
    /// Deserializuje regulator PID ze strumienia wejœciowego.
    /// </summary>
    /// <param name="in">Strumieñ wejœciowy (plikowy).</param>
    /// <returns>Wspó³dzielony wskaŸnik do zrekonstruowanego obiektu <c>RegulatorPID</c>.</returns>
    std::shared_ptr<RegulatorPID> DeserializujRegulator(std::ifstream& in);

    /// <summary>
    /// Umo¿liwia konfiguracjê sygna³u wejœciowego.
    /// </summary>
    void UstawieniaSygnalu();

    /// <summary>
    /// Umo¿liwia konfiguracjê modelu ARX.
    /// </summary>
    void UstawieniaModeluARX();

    /// <summary>
    /// Umo¿liwia konfiguracjê regulatora PID.
    /// </summary>
    void UstawieniaRegulatoraPID();

    /// <summary>
    /// Uruchamia symulacjê uk³adu na podstawie skonfigurowanego sygna³u, modelu ARX i regulatora PID.
    /// </summary>
    void UruchomSymulacjeUkladu();

    /// <summary>
    /// Zapisuje aktualn¹ konfiguracjê sygna³u, modelu ARX i regulatora PID do pliku.
    /// </summary>
    void ZapiszKonfiguracjeDoPliku();

    /// <summary>
    /// Wczytuje konfiguracjê sygna³u, modelu ARX i regulatora PID z pliku.
    /// </summary>
    void WczytajKonfiguracjeZPliku();

    /// <summary>
    /// Wyœwietla menu g³ówne programu i obs³uguje wybory u¿ytkownika.
    /// </summary>
    void PokazMenu();

public:
    /// <summary>
    /// Uruchamia g³ówny interfejs programu.
    /// </summary>
    void InterfejsStart();
};