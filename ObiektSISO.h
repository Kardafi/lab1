#pragma once


/// <summary>
/// Abstrakcyjna klasa bazowa reprezentuj�ca obiekt SISO (Single Input Single Output).
/// 
/// Definiuje interfejs dla system�w, kt�re na podstawie pojedynczego sygna�u wej�ciowego
/// generuj� pojedynczy sygna� wyj�ciowy.
/// </summary>
class ObiektSISO
{
public:
	virtual ~ObiektSISO() = default;

    /// <summary>
    /// Metoda czysto wirtualna symuluj�ca zachowanie obiektu SISO.
    /// Przyjmuje warto�� wej�ciow� i zwraca odpowiadaj�c� jej warto�� wyj�ciow�.
    /// </summary>
    /// <param name="wejscie">Warto�� sygna�u wej�ciowego.</param>
    /// <returns>Warto�� sygna�u wyj�ciowego.</returns>
	virtual double symuluj(double wejscie) = 0;

};

