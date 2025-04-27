#pragma once

#include "ModelARX.h"
#include "RegulatorPID.h"

/// <summary>
/// Klasa funktor, symuluj�ca jeden krok dzia�ania p�tli spr�enia zwrotnego.
/// </summary>
class Funktor
{
	double wartoscPoprzednia;

public:
	/// <summary>
	/// Domy�lny konstruktor klasy Funktor.
	/// </summary>
	Funktor();

	/// <summary>
	/// Przeci��ony operator wywo�ania funkcji.
	/// 
	/// Symuluje pojedynczy krok p�tli regulacji spr�enia zwrotnego:
	/// - Regulator PID przetwarza uchyb na sygna� steruj�cy.
	/// - Model ARX symuluje odpowied� obiektu na sygna� steruj�cy.
	/// - Operator zwraca now� warto�� wyj�ciow�.
	/// </summary>
	/// <param name="_modelARX">Obiekt modelu procesu (obiekt ARX).</param>
	/// <param name="_regulatorPID">Obiekt regulatora PID.</param>
	/// <param name="_WartoscZadana">Warto�� zadana (punkt odniesienia) dla systemu.</param>
	/// <returns>Warto�� wyj�ciowa modelu po kroku symulacji.</returns>
	double operator ()(ModelARX& _modelARX, RegulatorPID& _regulatorPID, double _wartoscZadana);

	
};

