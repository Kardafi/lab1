#pragma once
#include "PetlaUAR.h"
#pragma once

/// <summary>
/// Reprezentuje pêtlê regulacji UAR o strukturze równoleg³ej.
/// Wszystkie sk³adniki pêtli s¹ pod³¹czone równolegle – otrzymuj¹ ten sam sygna³ wejœciowy,
/// a ich odpowiedzi (wyjœcia) s¹ sumowane.
/// Mo¿e pracowaæ w trybie otwartym (bez sprzê¿enia zwrotnego) lub zamkniêtym (z uchybem).
/// </summary>
class PetlaRownolegla : public PetlaUAR
{
public:

    /// <summary>
    /// Dziedziczy konstruktor z klasy bazowej PetlaUAR.
    /// Dziêki temu mo¿na utworzyæ obiekt z parametrem okreœlaj¹cym tryb pracy.
    /// </summary>
    using PetlaUAR::PetlaUAR;

    /// <summary>
    /// Ustawia tryb pracy pêtli (otwarty lub zamkniêty).
    /// </summary>
    /// <param name="tryb">Nowy tryb pracy (OTWARTA lub ZAMKNIETA).</param>
    void UstawTryb(trybPracyPetli tryb) override;

    /// <summary>
    /// Zwraca aktualny tryb pracy pêtli.
    /// </summary>
    /// <returns>Aktualny tryb pracy.</returns>
    trybPracyPetli PobierzTryb() const override;

    /// <summary>
    /// Dodaje sk³adnik (np. regulator, model) na koniec listy.
    /// Wszystkie sk³adniki w strukturze równoleg³ej przetwarzaj¹ sygna³ niezale¿nie,
    /// a ich wyjœcia s¹ sumowane.
    /// </summary>
    /// <param name="skladnik">WskaŸnik do obiektu klasy ObiektSISO.</param>
    void DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik) override;

    /// <summary>
    /// Dodaje sk³adnik do konkretnej pozycji w liœcie sk³adników.
    /// </summary>
    /// <param name="skladnik">WskaŸnik do obiektu klasy ObiektSISO.</param>
    /// <param name="index">Pozycja w wektorze sk³adników, gdzie nale¿y dodaæ nowy obiekt.</param>
    void DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik, size_t index) override;

    /// <summary>
    /// Usuwa sk³adnik z listy na podstawie indeksu.
    /// </summary>
    /// <param name="index">Pozycja elementu do usuniêcia.</param>
    void UsunSkladnik(size_t index) override;

    /// <summary>
    /// Wykonuje symulacjê pêtli równoleg³ej:
    /// - W trybie OTWARTA ka¿dy sk³adnik otrzymuje wejœcie bez zmian.
    /// - W trybie ZAMKNIETA sk³adniki otrzymuj¹ uchyb = wejœcie - poprzednieWyjscie.
    /// - Wyjœcia wszystkich sk³adników s¹ sumowane.
    /// - W trybie ZAMKNIETA wynik sumowania jest zapamiêtywany jako nowe poprzednieWyjscie.
    /// </summary>
    /// <param name="wejscie">Sygna³ wejœciowy do pêtli.</param>
    /// <returns>Wyjœcie ca³ej pêtli (suma wyjœæ wszystkich sk³adników).</returns>
    double symuluj(double wejscie) override;
};

