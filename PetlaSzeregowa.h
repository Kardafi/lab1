#pragma once
#include "PetlaUAR.h"

/// <summary>
/// Reprezentuje p�tl� regulacji UAR o strukturze szeregowej.
/// Ka�dy sk�adnik p�tli otrzymuje wyj�cie poprzedniego sk�adnika jako swoje wej�cie.
/// Mo�e dzia�a� zar�wno w trybie otwartym, jak i zamkni�tym.
/// </summary>
class PetlaSzeregowa : public PetlaUAR
{
public:

    /// <summary>
    /// Dziedziczy konstruktor z klasy bazowej PetlaUAR.
    /// Dzi�ki temu mo�na tworzy� p�tle szeregowe w wybranym trybie pracy (otwarta lub zamkni�ta).
    /// </summary>
    using PetlaUAR::PetlaUAR;

    /// <summary>
    /// Ustawia tryb pracy p�tli (np. prze��czenie z otwartej na zamkni�t�).
    /// </summary>
    /// <param name="tryb">Nowy tryb pracy: OTWARTA lub ZAMKNIETA.</param>
    void UstawTryb(trybPracyPetli tryb) override;

    /// <summary>
    /// Zwraca aktualny tryb pracy p�tli.
    /// </summary>
    /// <returns>Aktualnie ustawiony tryb: OTWARTA lub ZAMKNIETA.</returns>
    trybPracyPetli PobierzTryb() const override;

    /// <summary>
    /// Dodaje sk�adnik (np. regulator, model ARX) na koniec ci�gu element�w szeregowych.
    /// Sygna� przechodzi przez ka�dy z element�w po kolei.
    /// </summary>
    /// <param name="skladnik">Inteligentny wska�nik do obiektu klasy ObiektSISO.</param>
    void DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik) override;

    /// <summary>
    /// Dodaje sk�adnik do wskazanej pozycji w szeregu sk�adnik�w.
    /// Pozwala wstawi� nowy element mi�dzy istniej�ce sk�adniki.
    /// </summary>
    /// <param name="skladnik">Wska�nik do obiektu klasy ObiektSISO.</param>
    /// <param name="index">Indeks pozycji w wektorze sk�adnik�w.</param>
    void DodajSkladnik(std::shared_ptr<ObiektSISO> skladnik, size_t index) override;

    /// <summary>
    /// Usuwa sk�adnik z listy wed�ug indeksu.
    /// </summary>
    /// <param name="index">Indeks sk�adnika do usuni�cia.</param>
    void UsunSkladnik(size_t index) override;

    /// <summary>
    /// Przeprowadza symulacj� p�tli szeregowej.
    /// - W trybie OTWARTA: wej�cie przekazywane jest do pierwszego sk�adnika.
    ///   Ka�dy kolejny sk�adnik przetwarza wynik poprzedniego.
    /// - W trybie ZAMKNIETA: obliczany jest uchyb = wej�cie - poprzednieWyjscie,
    ///   kt�ry staje si� sygna�em wej�ciowym dla pierwszego sk�adnika.
    /// - Wynik ko�cowy (wyj�cie ostatniego sk�adnika) jest pami�tany jako poprzednieWyjscie.
    /// </summary>
    /// <param name="wejscie">Sygna� wej�ciowy do ca�ej p�tli.</param>
    /// <returns>Wyj�cie p�tli po przej�ciu przez wszystkie sk�adniki.</returns>
    double symuluj(double wejscie) override;
};