#pragma once
#include "Komponent.h"
#include <list>
class KompozytRownolegly : public Komponent
{
	std::list <Komponent*> komponenty; ///< Lista komponent�w w kompozycie r�wnoleg�ym.
public:
	/// <summary>
	/// Konstruktor domy�lny.
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
	/// Symuluje zachowanie kompozytu r�wnoleg�ego na podstawie podanego sygna�u wej�ciowego.
	/// </summary>
	double symuluj(double wejscie);
};

