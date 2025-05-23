#pragma once
#include "Komponent.h"
#include <list>
class KompozytSzeregowy : public Komponent
{
	std::list <Komponent*> komponenty; ///< Lista komponentów w kompozycie szeregowym.
public:
	/// <summary>
	/// Konstruktor domyślny.
	/// </summary>
	KompozytSzeregowy();
	/// <summary>
	/// Destruktor.
	/// </summary>
	virtual ~KompozytSzeregowy();
	/// <summary>
	/// Dodaje komponent do kompozytu.
	/// </summary>
	void dodaj(Komponent* komponent);
	/// <summary>
	/// Usuwa komponent z kompozytu.
	/// </summary>
	void usun(Komponent* komponent);
	/// <summary>
	/// Zwraca dziecko o podanym indeksie.
	/// </summary>
	Komponent* getChild(int n);

	/// <summary>
	/// Symuluje zachowanie kompozytu szeregowego na podstawie podanego sygnału wejściowego.
	/// </summary>
	double symuluj(double wejscie);

};

