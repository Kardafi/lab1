#pragma once
#include "ObiektSISO.h"
#include <vector>
#include <memory>
#include <iostream>

/// <summary>
/// Wyliczenie trybu pracy p�tli (otwarta lub zamkni�ta).
/// OTWARTA � brak sprz�enia zwrotnego (wyj�cie nie wp�ywa na wej�cie).
/// ZAMKNIETA � zrealizowane sprz�enie zwrotne (np. sterowanie z ujemnym uchybem).
/// </summary>
enum class trybPracyPetli { OTWARTA, ZAMKNIETA };

/// <summary>
/// Bazowa klasa abstrakcyjna reprezentuj�ca p�tl� regulacji UAR (Uk�ad Automatycznej Regulacji).
/// Umo�liwia budow� dowolnej struktury p�tli (szeregowej, r�wnoleg�ej, mieszanej),
/// w kt�rej mo�na ��czy� wiele obiekt�w SISO (Single Input, Single Output),
/// takich jak regulatory, modele proces�w, filtry itp.
/// </summary>
class PetlaUAR : public ObiektSISO
{
protected:

    /// <summary>
    /// Tryb pracy p�tli: otwarty (brak sprz�enia zwrotnego) lub zamkni�ty (z uchybem).
    /// </summary>
    trybPracyPetli trybPracy;

    /// <summary>
    /// Wektor wska�nik�w do sk�adnik�w p�tli. Sk�adniki musz� implementowa� interfejs ObiektSISO.
    /// Dzi�ki temu mo�na ��czy� r�ne elementy systemu regulacji w elastyczny spos�b.
    /// </summary>
    std::vector<std::shared_ptr<ObiektSISO>> skladniki;

    /// <summary>
    /// Poprzednia warto�� wyj�ciowa p�tli. W trybie zamkni�tym s�u�y jako warto�� sprz�enia zwrotnego
    /// przy obliczaniu uchybu regulacji.
    /// </summary>
    double poprzednieWyjscie;

public:
    /// <summary>
    /// Wirtualny destruktor � umo�liwia poprawne zarz�dzanie pami�ci� w klasach pochodnych.
    /// </summary>
    virtual ~PetlaUAR() = default;

    /// <summary>
    /// Konstruktor z parametrem inicjalizuj�cym tryb pracy.
    /// Domy�lnie inicjuje tryb oraz zeruje poprzednie wyj�cie.
    /// </summary>
    /// <param name="_tryb">Tryb pracy p�tli: OTWARTA lub ZAMKNIETA.</param>
    PetlaUAR(trybPracyPetli _tryb);

    /// <summary>
    /// Metoda umo�liwiaj�ca zmian� trybu pracy p�tli w czasie dzia�ania programu.
    /// </summary>
    /// <param name="tryb">Nowy tryb pracy p�tli.</param>
    virtual void UstawTryb(trybPracyPetli tryb);

    /// <summary>
    /// Zwraca aktualnie ustawiony tryb pracy p�tli.
    /// U�yteczne np. w UI do synchronizacji stanu systemu z widokiem.
    /// </summary>
    virtual trybPracyPetli PobierzTryb() const;

    /// <summary>
    /// Dodaje sk�adnik (np. regulator PID, filtr, model) na koniec listy sk�adnik�w.
    /// Elementy s� wykonywane w kolejno�ci dodania.
    /// </summary>
    /// <param name="skladnik">Inteligentny wska�nik do obiektu klasy implementuj�cej ObiektSISO.</param>
    virtual void DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik);

    /// <summary>
    /// Dodaje sk�adnik do listy sk�adnik�w pod okre�lonym indeksem.
    /// Pozwala wstawi� element mi�dzy innymi sk�adnikami.
    /// </summary>
    /// <param name="skladnik">Wska�nik do sk�adnika.</param>
    /// <param name="index">Pozycja w wektorze sk�adnik�w.</param>
    virtual void DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik, size_t index);

    /// <summary>
    /// Usuwa sk�adnik z listy na podstawie indeksu.
    /// </summary>
    /// <param name="index">Pozycja w li�cie sk�adnik�w do usuni�cia.</param>
    virtual void UsunSkladnik(size_t index);

    /// <summary>
    /// Metoda symulacji dzia�ania p�tli regulacji.
    /// Musi zosta� przes�oni�ta przez klas� pochodn� (szeregowa, r�wnoleg�a).
    /// </summary>
    /// <param name="wejscie">Warto�� sygna�u wej�ciowego do p�tli.</param>
    /// <returns>Warto�� sygna�u wyj�ciowego po przej�ciu przez wszystkie sk�adniki.</returns>
    virtual double symuluj(double wejscie) = 0;
};


