#pragma once
#include "ObiektSISO.h"
#include <vector>
#include <memory>
#include <iostream>

/// <summary>
/// Wyliczenie trybu pracy pêtli (otwarta lub zamkniêta).
/// OTWARTA – brak sprzê¿enia zwrotnego (wyjœcie nie wp³ywa na wejœcie).
/// ZAMKNIETA – zrealizowane sprzê¿enie zwrotne (np. sterowanie z ujemnym uchybem).
/// </summary>
enum class trybPracyPetli { OTWARTA, ZAMKNIETA };

/// <summary>
/// Bazowa klasa abstrakcyjna reprezentuj¹ca pêtlê regulacji UAR (Uk³ad Automatycznej Regulacji).
/// Umo¿liwia budowê dowolnej struktury pêtli (szeregowej, równoleg³ej, mieszanej),
/// w której mo¿na ³¹czyæ wiele obiektów SISO (Single Input, Single Output),
/// takich jak regulatory, modele procesów, filtry itp.
/// </summary>
class PetlaUAR : public ObiektSISO
{
protected:

    /// <summary>
    /// Tryb pracy pêtli: otwarty (brak sprzê¿enia zwrotnego) lub zamkniêty (z uchybem).
    /// </summary>
    trybPracyPetli trybPracy;

    /// <summary>
    /// Wektor wskaŸników do sk³adników pêtli. Sk³adniki musz¹ implementowaæ interfejs ObiektSISO.
    /// Dziêki temu mo¿na ³¹czyæ ró¿ne elementy systemu regulacji w elastyczny sposób.
    /// </summary>
    std::vector<std::shared_ptr<ObiektSISO>> skladniki;

    /// <summary>
    /// Poprzednia wartoœæ wyjœciowa pêtli. W trybie zamkniêtym s³u¿y jako wartoœæ sprzê¿enia zwrotnego
    /// przy obliczaniu uchybu regulacji.
    /// </summary>
    double poprzednieWyjscie;

public:
    /// <summary>
    /// Wirtualny destruktor – umo¿liwia poprawne zarz¹dzanie pamiêci¹ w klasach pochodnych.
    /// </summary>
    virtual ~PetlaUAR() = default;

    /// <summary>
    /// Konstruktor z parametrem inicjalizuj¹cym tryb pracy.
    /// Domyœlnie inicjuje tryb oraz zeruje poprzednie wyjœcie.
    /// </summary>
    /// <param name="_tryb">Tryb pracy pêtli: OTWARTA lub ZAMKNIETA.</param>
    PetlaUAR(trybPracyPetli _tryb);

    /// <summary>
    /// Metoda umo¿liwiaj¹ca zmianê trybu pracy pêtli w czasie dzia³ania programu.
    /// </summary>
    /// <param name="tryb">Nowy tryb pracy pêtli.</param>
    virtual void UstawTryb(trybPracyPetli tryb);

    /// <summary>
    /// Zwraca aktualnie ustawiony tryb pracy pêtli.
    /// U¿yteczne np. w UI do synchronizacji stanu systemu z widokiem.
    /// </summary>
    virtual trybPracyPetli PobierzTryb() const;

    /// <summary>
    /// Dodaje sk³adnik (np. regulator PID, filtr, model) na koniec listy sk³adników.
    /// Elementy s¹ wykonywane w kolejnoœci dodania.
    /// </summary>
    /// <param name="skladnik">Inteligentny wskaŸnik do obiektu klasy implementuj¹cej ObiektSISO.</param>
    virtual void DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik);

    /// <summary>
    /// Dodaje sk³adnik do listy sk³adników pod okreœlonym indeksem.
    /// Pozwala wstawiæ element miêdzy innymi sk³adnikami.
    /// </summary>
    /// <param name="skladnik">WskaŸnik do sk³adnika.</param>
    /// <param name="index">Pozycja w wektorze sk³adników.</param>
    virtual void DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik, size_t index);

    /// <summary>
    /// Usuwa sk³adnik z listy na podstawie indeksu.
    /// </summary>
    /// <param name="index">Pozycja w liœcie sk³adników do usuniêcia.</param>
    virtual void UsunSkladnik(size_t index);

    /// <summary>
    /// Metoda symulacji dzia³ania pêtli regulacji.
    /// Musi zostaæ przes³oniêta przez klasê pochodn¹ (szeregowa, równoleg³a).
    /// </summary>
    /// <param name="wejscie">Wartoœæ sygna³u wejœciowego do pêtli.</param>
    /// <returns>Wartoœæ sygna³u wyjœciowego po przejœciu przez wszystkie sk³adniki.</returns>
    virtual double symuluj(double wejscie) = 0;
};


