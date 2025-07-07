#pragma once
#include "PetlaUAR.h"
#pragma once

/// <summary>
/// Reprezentuje p�tl� regulacji UAR o strukturze r�wnoleg�ej.
/// Wszystkie sk�adniki p�tli s� pod��czone r�wnolegle � otrzymuj� ten sam sygna� wej�ciowy,
/// a ich odpowiedzi (wyj�cia) s� sumowane.
/// Mo�e pracowa� w trybie otwartym (bez sprz�enia zwrotnego) lub zamkni�tym (z uchybem).
/// </summary>
class PetlaRownolegla : public PetlaUAR
{
public:

    /// <summary>
    /// Dziedziczy konstruktor z klasy bazowej PetlaUAR.
    /// Dzi�ki temu mo�na utworzy� obiekt z parametrem okre�laj�cym tryb pracy.
    /// </summary>
    using PetlaUAR::PetlaUAR;

    /// <summary>
    /// Ustawia tryb pracy p�tli (otwarty lub zamkni�ty).
    /// </summary>
    /// <param name="tryb">Nowy tryb pracy (OTWARTA lub ZAMKNIETA).</param>
    void UstawTryb(trybPracyPetli tryb) override;

    /// <summary>
    /// Zwraca aktualny tryb pracy p�tli.
    /// </summary>
    /// <returns>Aktualny tryb pracy.</returns>
    trybPracyPetli PobierzTryb() const override;

    /// <summary>
    /// Dodaje sk�adnik (np. regulator, model) na koniec listy.
    /// Wszystkie sk�adniki w strukturze r�wnoleg�ej przetwarzaj� sygna� niezale�nie,
    /// a ich wyj�cia s� sumowane.
    /// </summary>
    /// <param name="skladnik">Wska�nik do obiektu klasy ObiektSISO.</param>
    void DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik) override;

    /// <summary>
    /// Dodaje sk�adnik do konkretnej pozycji w li�cie sk�adnik�w.
    /// </summary>
    /// <param name="skladnik">Wska�nik do obiektu klasy ObiektSISO.</param>
    /// <param name="index">Pozycja w wektorze sk�adnik�w, gdzie nale�y doda� nowy obiekt.</param>
    void DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik, size_t index) override;

    /// <summary>
    /// Usuwa sk�adnik z listy na podstawie indeksu.
    /// </summary>
    /// <param name="index">Pozycja elementu do usuni�cia.</param>
    void UsunSkladnik(size_t index) override;

    /// <summary>
    /// Wykonuje symulacj� p�tli r�wnoleg�ej:
    /// - W trybie OTWARTA ka�dy sk�adnik otrzymuje wej�cie bez zmian.
    /// - W trybie ZAMKNIETA sk�adniki otrzymuj� uchyb = wej�cie - poprzednieWyjscie.
    /// - Wyj�cia wszystkich sk�adnik�w s� sumowane.
    /// - W trybie ZAMKNIETA wynik sumowania jest zapami�tywany jako nowe poprzednieWyjscie.
    /// </summary>
    /// <param name="wejscie">Sygna� wej�ciowy do p�tli.</param>
    /// <returns>Wyj�cie ca�ej p�tli (suma wyj�� wszystkich sk�adnik�w).</returns>
    double symuluj(double wejscie) override;
};

