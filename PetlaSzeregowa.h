#pragma once
#include "PetlaUAR.h"

/// <summary>
/// Reprezentuje pêtlê regulacji UAR o strukturze szeregowej.
/// Ka¿dy sk³adnik pêtli otrzymuje wyjœcie poprzedniego sk³adnika jako swoje wejœcie.
/// Mo¿e dzia³aæ zarówno w trybie otwartym, jak i zamkniêtym.
/// </summary>
class PetlaSzeregowa : public PetlaUAR
{
public:

    /// <summary>
    /// Dziedziczy konstruktor z klasy bazowej PetlaUAR.
    /// Dziêki temu mo¿na tworzyæ pêtle szeregowe w wybranym trybie pracy (otwarta lub zamkniêta).
    /// </summary>
    using PetlaUAR::PetlaUAR;

    /// <summary>
    /// Ustawia tryb pracy pêtli (np. prze³¹czenie z otwartej na zamkniêt¹).
    /// </summary>
    /// <param name="tryb">Nowy tryb pracy: OTWARTA lub ZAMKNIETA.</param>
    void UstawTryb(trybPracyPetli tryb) override;

    /// <summary>
    /// Zwraca aktualny tryb pracy pêtli.
    /// </summary>
    /// <returns>Aktualnie ustawiony tryb: OTWARTA lub ZAMKNIETA.</returns>
    trybPracyPetli PobierzTryb() const override;

    /// <summary>
    /// Dodaje sk³adnik (np. regulator, model ARX) na koniec ci¹gu elementów szeregowych.
    /// Sygna³ przechodzi przez ka¿dy z elementów po kolei.
    /// </summary>
    /// <param name="skladnik">Inteligentny wskaŸnik do obiektu klasy ObiektSISO.</param>
    void DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik) override;

    /// <summary>
    /// Dodaje sk³adnik do wskazanej pozycji w szeregu sk³adników.
    /// Pozwala wstawiæ nowy element miêdzy istniej¹ce sk³adniki.
    /// </summary>
    /// <param name="skladnik">WskaŸnik do obiektu klasy ObiektSISO.</param>
    /// <param name="index">Indeks pozycji w wektorze sk³adników.</param>
    void DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik, size_t index) override;

    /// <summary>
    /// Usuwa sk³adnik z listy wed³ug indeksu.
    /// </summary>
    /// <param name="index">Indeks sk³adnika do usuniêcia.</param>
    void UsunSkladnik(size_t index) override;

    /// <summary>
    /// Przeprowadza symulacjê pêtli szeregowej.
    /// - W trybie OTWARTA: wejœcie przekazywane jest do pierwszego sk³adnika.
    ///   Ka¿dy kolejny sk³adnik przetwarza wynik poprzedniego.
    /// - W trybie ZAMKNIETA: obliczany jest uchyb = wejœcie - poprzednieWyjscie,
    ///   który staje siê sygna³em wejœciowym dla pierwszego sk³adnika.
    /// - Wynik koñcowy (wyjœcie ostatniego sk³adnika) jest pamiêtany jako poprzednieWyjscie.
    /// </summary>
    /// <param name="wejscie">Sygna³ wejœciowy do ca³ej pêtli.</param>
    /// <returns>Wyjœcie pêtli po przejœciu przez wszystkie sk³adniki.</returns>
    double symuluj(double wejscie) override;
};