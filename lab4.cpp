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

#define asddsd

#ifdef MAIN4

int main() {

        // Tworzenie dwóch modeli ARX jako liœci
        ModelARX arx1({ -0.4 }, { 0.6 }, 1, 0);
        ModelARX arx2({ -0.4 }, { 0.6 }, 1, 0);
        ModelARX arx3({ 0.7 }, { -0.2 }, 1, 0); // dodatkowy model do po³¹czenia szeregowego

        // Opakowanie modeli jako komponenty
        Komponent* komponent1 = new ModelARXKomponent(arx1);
        Komponent* komponent2 = new ModelARXKomponent(arx2);
        Komponent* komponent3 = new ModelARXKomponent(arx3);

        // Kompozyt równoleg³y: (arx1 || arx2)
        KompozytRownolegly* rowno = new KompozytRownolegly();
        rowno->dodaj(komponent1);
        rowno->dodaj(komponent2);

        // Kompozyt szeregowy: (arx1 || arx2) -> arx3
        KompozytSzeregowy* szereg = new KompozytSzeregowy();
        szereg->dodaj(rowno);     // pierwszy etap - po³¹czenie równoleg³e
        szereg->dodaj(komponent3); // drugi etap - model szeregowy

        // Symulacja
        double wejscie = 1.0;
        for (int i = 0; i < 100; ++i) {
            double wyjscie = szereg->symuluj(wejscie);
            std::cout << "krok " << i << " -> wyjscie: " << wyjscie << std::endl;
            wejscie = 0.0; // impuls tylko na pocz¹tku
        }

        delete szereg;
        return 0;

}

#endif // MAIN4