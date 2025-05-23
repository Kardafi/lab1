#pragma once
#include "Komponent.h"
#include <list>
class KompozytRownolegly : public Komponent
{
	std::list <Komponent*> komponenty; ///< Lista komponentów w kompozycie równoległym.
public:
	/// <summary>
	/// Konstruktor domyślny.
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
	/// Symuluje zachowanie kompozytu równoległego na podstawie podanego sygnału wejściowego.
	/// </summary>
	double symuluj(double wejscie);
};

