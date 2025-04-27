#pragma once


/// <summary>
/// Abstrakcyjna klasa bazowa reprezentuj¹ca obiekt SISO (Single Input Single Output).
/// 
/// Definiuje interfejs dla systemów, które na podstawie pojedynczego sygna³u wejœciowego
/// generuj¹ pojedynczy sygna³ wyjœciowy.
/// </summary>
class ObiektSISO
{
public:
	virtual ~ObiektSISO() = default;

    /// <summary>
    /// Metoda czysto wirtualna symuluj¹ca zachowanie obiektu SISO.
    /// Przyjmuje wartoœæ wejœciow¹ i zwraca odpowiadaj¹c¹ jej wartoœæ wyjœciow¹.
    /// </summary>
    /// <param name="wejscie">Wartoœæ sygna³u wejœciowego.</param>
    /// <returns>Wartoœæ sygna³u wyjœciowego.</returns>
	virtual double symuluj(double wejscie) = 0;

};

