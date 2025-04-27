#include "Funktor.h"

double Funktor::operator()(ModelARX& _modelARX, RegulatorPID& _regulatorPID, double _probka)
{
    // Krok 1: Wylicz uchyb jako r�nic� mi�dzy warto�ci� zadan� a poprzedni� warto�ci� wyj�cia modelu
    double wartoscPoprzednia = _modelARX.getWyjscie();
    double uchyb = _probka - wartoscPoprzednia;

    // Krok 2: Zasymuluj kilka krok�w regulatora PID (np. 3 kroki)
    double sterowanie = 0.0;
    for (int i = 0; i < 10; ++i) {
        sterowanie = _regulatorPID.symuluj(uchyb);
    }

    // Krok 3: Przeka� sterowanie do modelu ARX i wykonaj symulacj� jednego kroku
    double wyjscie = _modelARX.symuluj(sterowanie);

    // Krok 4: Zwr�� warto�� regulowan�
    return wyjscie;
}
