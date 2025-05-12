#pragma once
#include "Komponent.h"
#include <list>
class KompozytRownolegly : public Komponent
{
	std::list <Komponent*> komponenty; ///< Lista komponentów w kompozycie równoleg³ym.
public:
	/// <summary>
	/// Konstruktor domyœlny.
	/// </summary>
	KompozytRownolegly();
	/// <summary>
	/// Destruktor.
	/// </summary>
	virtual ~KompozytRownolegly();
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
	/// Symuluje zachowanie kompozytu równoleg³ego na podstawie podanego sygna³u wejœciowego.
	/// </summary>
	double symuluj(double wejscie);
};

