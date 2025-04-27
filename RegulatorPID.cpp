#include "RegulatorPID.h"

RegulatorPID::RegulatorPID(double _k) : k(_k)
{
	Ti = 0;
	Td = 0;
}

RegulatorPID::RegulatorPID(double _k, double _Ti) : k(_k), Ti(_Ti)
{
	Td = 0;
}

RegulatorPID::RegulatorPID(double _k, double _Ti, double _Td) : k(_k), Ti(_Ti), Td(_Td)
{
}

RegulatorPID::~RegulatorPID()
{
}

double RegulatorPID::symuluj(double wejscie)
{
	pamiecUchyl.push_back(wejscie);
	double wynik = k * wejscie;

	if (Ti > 0) { //PI
		double suma = 0;
		for (auto elem : pamiecUchyl) {
			suma += elem;
		}

		wynik += (1 / Ti) * suma;
	}
	if (Td > 0) { //PID
		if (pamiecUchyl.size() >= 2) {
			wynik += Td * (pamiecUchyl.back() - pamiecUchyl.at(pamiecUchyl.size() - 2));
		}

	}

	return wynik;
}

void RegulatorPID::setK(double _k)
{
	if (SprawdzNastawe(_k))
		k = _k;
	else
		std::cerr << "Blad! Niepoprawna wartosc k!";
}

void RegulatorPID::setTi(double _Ti)
{
	if (SprawdzNastawe(_Ti))
		Ti = _Ti;
	else
		std::cerr << "Blad! Niepoprawna wartosc Ti!";
}

void RegulatorPID::setTd(double _Td)
{
	if (SprawdzNastawe(_Td))
		Td = _Td;
	else
		std::cerr << "Blad! Niepoprawna wartosc Td!";
}

int RegulatorPID::SprawdzNastawe(double _nastawa)
{
	if (_nastawa > 0) return 1;
	else return 0;
}
