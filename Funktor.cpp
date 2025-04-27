#include "Funktor.h"

Funktor::Funktor() : wartoscPoprzednia(0.0) {}

double Funktor::operator()(ModelARX& _modelARX, RegulatorPID& _regulatorPID, double _wartoscZadana)
{
    //uchyb -> r�nica mi�dzy warto�ci� zadan� a poprzedni� warto�ci� wyj�cia modelu
    double uchyb = _wartoscZadana - wartoscPoprzednia;

    //symulacja kilku krok�w regulatora PID
    double sterowanie = 0.0;
    for (int i = 0; i < 10; ++i) {
        sterowanie = _regulatorPID.symuluj(uchyb);
    }

    //symulacja dzia�ania modelu ARX
    wartoscPoprzednia = _modelARX.symuluj(sterowanie);

    //zwr�cenie warto�ci regulowanej
    return wartoscPoprzednia;
}
