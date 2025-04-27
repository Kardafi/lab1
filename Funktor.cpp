#include "Funktor.h"

Funktor::Funktor() : wartoscPoprzednia(0.0) {}

double Funktor::operator()(ModelARX& _modelARX, RegulatorPID& _regulatorPID, double _wartoscZadana)
{
    //uchyb -> ró¿nica miêdzy wartoœci¹ zadan¹ a poprzedni¹ wartoœci¹ wyjœcia modelu
    double uchyb = _wartoscZadana - wartoscPoprzednia;

    //symulacja kilku kroków regulatora PID
    double sterowanie = 0.0;
    for (int i = 0; i < 10; ++i) {
        sterowanie = _regulatorPID.symuluj(uchyb);
    }

    //symulacja dzia³ania modelu ARX
    wartoscPoprzednia = _modelARX.symuluj(sterowanie);

    //zwrócenie wartoœci regulowanej
    return wartoscPoprzednia;
}
