#include <iostream>
#include "Generator.h"
#include "GeneratorStala.h"
#include "GeneratorDekorator.h"
#include "SygnalSinusDekorator.h"
#include "SygnalProstokatnyDekorator.h"
#include "SygnalTrojkatnyDekorator.h"
#include "OgraniczenieAmplitudyDekorator.h"
#include "SygnalBialySzum.h"

#include "KompozytRownolegly.h"
#include "KompozytSzeregowy.h"
#include "ModelARXKomponent.h"
#include "ModelARX.h"

#define MAIN4

#ifdef MAIN4

int main() {

        // Tworzenie dwóch modeli ARX jako liœci
        ModelARX arx1({ -0.4 }, { 0.6 }, 1, 0);
        ModelARX arx2({ -0.4 }, { 0.6 }, 1, 0); 

        Komponent* komponent1 = new ModelARXKomponent(arx1);
        Komponent* komponent2 = new ModelARXKomponent(arx2);

        // Kompozyt szeregowy
        KompozytRownolegly* rowno = new KompozytRownolegly();
        rowno->dodaj(komponent1);
        rowno->dodaj(komponent2);

        // Symulacja
        double wejscie = 1.0;
        for (int i = 0; i < 100; ++i) {
            double wyjscie = rowno->symuluj(wejscie);
            std::cout << "krok " << i << " -> wyjscie: " << wyjscie << std::endl;
            wejscie = 0.0; // np. impuls jednostkowy tylko na pocz¹tku
        }

        delete rowno;
        return 0;
}

#endif // MAIN4