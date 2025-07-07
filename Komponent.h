#pragma once
#include "ObiektSISO.h"
/// <summary>
/// Abstrakcyjna klasa bazowa reprezentuj¹ca komponent w strukturze z³o¿onego uk³adu.
/// Dziedziczy po <c>ObiektSISO</c> i umo¿liwia implementacjê wzorca Composite.
/// </summary>
class Komponent : public ObiektSISO
{
public:
    /// <summary>
    /// Metoda czysto wirtualna do symulacji dzia³ania komponentu dla danego wejœcia.
    /// </summary>
    /// <param name="wejscie">Wartoœæ wejœciowa sygna³u typu <c>double</c>.</param>
    /// <returns>Wartoœæ wyjœciowa po przetworzeniu przez komponent.</returns>
    virtual double symuluj(double wejscie) = 0;

    /// <summary>
    /// Dodaje komponent podrzêdny do bie¿¹cego komponentu.
    /// Domyœlnie nie robi nic — powinno byæ nadpisane w klasach z³o¿onych.
    /// </summary>
    /// <param name="komponent">WskaŸnik do dodawanego komponentu.</param>
    virtual void dodaj(Komponent* komponent);

    /// <summary>
    /// Usuwa komponent podrzêdny z bie¿¹cego komponentu.
    /// Domyœlnie nie robi nic — powinno byæ nadpisane w klasach z³o¿onych.
    /// </summary>
    /// <param name="komponent">WskaŸnik do usuwanego komponentu.</param>
    virtual void usun(Komponent* komponent);

    /// <summary>
    /// Zwraca wskaŸnik do podrzêdnego komponentu o podanym indeksie.
    /// Domyœlnie zwraca <c>nullptr</c> — powinno byæ nadpisane w klasach z³o¿onych.
    /// </summary>
    /// <param name="n">Indeks komponentu podrzêdnego.</param>
    /// <returns>WskaŸnik do komponentu podrzêdnego lub <c>nullptr</c>, jeœli nie istnieje.</returns>
    virtual Komponent* getChild(int n);

    /// <summary>
    /// Wirtualny destruktor klasy <c>Komponent</c>.
    /// Umo¿liwia bezpieczne usuwanie obiektów dziedzicz¹cych przez wskaŸnik do klasy bazowej.
    /// </summary>
    virtual ~Komponent() = default;
};

