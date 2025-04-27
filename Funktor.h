#pragma once

#include "ModelARX.h"
#include "RegulatorPID.h"

/// <summary>
/// Klasa funktor, symuluj¹ca jeden krok dzia³ania pêtli sprê¿enia zwrotnego.
/// </summary>
class Funktor
{
	double wartoscPoprzednia;

public:
	/// <summary>
	/// Domyœlny konstruktor klasy Funktor.
	/// </summary>
	Funktor();

	/// <summary>
	/// Przeci¹¿ony operator wywo³ania funkcji.
	/// 
	/// Symuluje pojedynczy krok pêtli regulacji sprê¿enia zwrotnego:
	/// - Regulator PID przetwarza uchyb na sygna³ steruj¹cy.
	/// - Model ARX symuluje odpowiedŸ obiektu na sygna³ steruj¹cy.
	/// - Operator zwraca now¹ wartoœæ wyjœciow¹.
	/// </summary>
	/// <param name="_modelARX">Obiekt modelu procesu (obiekt ARX).</param>
	/// <param name="_regulatorPID">Obiekt regulatora PID.</param>
	/// <param name="_WartoscZadana">Wartoœæ zadana (punkt odniesienia) dla systemu.</param>
	/// <returns>Wartoœæ wyjœciowa modelu po kroku symulacji.</returns>
	double operator ()(ModelARX& _modelARX, RegulatorPID& _regulatorPID, double _wartoscZadana);

	
};

