#pragma once
#include "ObiektSISO.h"
/// <summary>
/// Abstrakcyjna klasa bazowa reprezentuj�ca komponent w strukturze z�o�onego uk�adu.
/// Dziedziczy po <c>ObiektSISO</c> i umo�liwia implementacj� wzorca Composite.
/// </summary>
class Komponent : public ObiektSISO
{
public:
    /// <summary>
    /// Metoda czysto wirtualna do symulacji dzia�ania komponentu dla danego wej�cia.
    /// </summary>
    /// <param name="wejscie">Warto�� wej�ciowa sygna�u typu <c>double</c>.</param>
    /// <returns>Warto�� wyj�ciowa po przetworzeniu przez komponent.</returns>
    virtual double symuluj(double wejscie) = 0;

    /// <summary>
    /// Dodaje komponent podrz�dny do bie��cego komponentu.
    /// Domy�lnie nie robi nic � powinno by� nadpisane w klasach z�o�onych.
    /// </summary>
    /// <param name="komponent">Wska�nik do dodawanego komponentu.</param>
    virtual void dodaj(Komponent* komponent);

    /// <summary>
    /// Usuwa komponent podrz�dny z bie��cego komponentu.
    /// Domy�lnie nie robi nic � powinno by� nadpisane w klasach z�o�onych.
    /// </summary>
    /// <param name="komponent">Wska�nik do usuwanego komponentu.</param>
    virtual void usun(Komponent* komponent);

    /// <summary>
    /// Zwraca wska�nik do podrz�dnego komponentu o podanym indeksie.
    /// Domy�lnie zwraca <c>nullptr</c> � powinno by� nadpisane w klasach z�o�onych.
    /// </summary>
    /// <param name="n">Indeks komponentu podrz�dnego.</param>
    /// <returns>Wska�nik do komponentu podrz�dnego lub <c>nullptr</c>, je�li nie istnieje.</returns>
    virtual Komponent* getChild(int n);

    /// <summary>
    /// Wirtualny destruktor klasy <c>Komponent</c>.
    /// Umo�liwia bezpieczne usuwanie obiekt�w dziedzicz�cych przez wska�nik do klasy bazowej.
    /// </summary>
    virtual ~Komponent() = default;
};

