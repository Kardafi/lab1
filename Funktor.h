#pragma once

#include "ModelARX.h"
#include "RegulatorPID.h"

class Funktor
{
public:
	//Funktor();

	//double uchyb;
	//double wartoscPoprzednia;

public:
	double operator ()(ModelARX& _modelARX, RegulatorPID& _regulatorPID, double _probka);

	
};

