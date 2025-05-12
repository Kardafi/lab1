#pragma once
#include "ObiektSISO.h"
class Komponent : public ObiektSISO
{

public:
	virtual double symuluj(double wejscie)=0;
	virtual void dodaj(Komponent*);
	virtual void usun(Komponent*);
	virtual Komponent* getChild(int n);
	virtual ~Komponent() = default;

};

