#include "Funktor.h"

double Funktor::operator()(ModelARX& _modelARX, RegulatorPID& _regulatorPID, double _probka)
{
    // Krok 1: Wylicz uchyb jako ró¿nicê miêdzy wartoœci¹ zadan¹ a poprzedni¹ wartoœci¹ wyjœcia modelu
    double wartoscPoprzednia = _modelARX.getWyjscie();
    double uchyb = _probka - wartoscPoprzednia;

    // Krok 2: Zasymuluj kilka kroków regulatora PID (np. 3 kroki)
    double sterowanie = 0.0;
    for (int i = 0; i < 10; ++i) {
        sterowanie = _regulatorPID.symuluj(uchyb);
    }

    // Krok 3: Przeka¿ sterowanie do modelu ARX i wykonaj symulacjê jednego kroku
    double wyjscie = _modelARX.symuluj(sterowanie);

    // Krok 4: Zwróæ wartoœæ regulowan¹
    return wyjscie;
}
