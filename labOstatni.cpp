#include <iostream>
#include <fstream>
#include "ModelARX.h"
#include "RegulatorPID.h"
#include <memory>


#include "GeneratorStala.h"
#include "SygnalSinusDekorator.h"
#include "SygnalProstokatnyDekorator.h"
#include "SygnalTrojkatnyDekorator.h"
#include "SygnalBialySzum.h"
#include "OgraniczenieAmplitudyDekorator.h"

#include  "PetlaSzeregowa.h"
#include "PetlaRownolegla.h"

#include "Interfejs.h"
#include <iomanip>

int main() {

#ifdef TEST_PETLI



    std::vector<double> wspA = { -0.4, 0.2 };
    std::vector<double> wspB = { 0.6, 0.3 };
    int opoznienie = 0;
    double mocZaklocenia = 0.0;

    auto regulator = std::make_shared<RegulatorPID>(0.5, 10.0, 0.1);
    auto model1 = std::make_shared<ModelARX>(wspA, wspB, opoznienie, mocZaklocenia);
    auto model2 = std::make_shared<ModelARX>(wspA, wspB, opoznienie, mocZaklocenia);
    auto model3 = std::make_shared<ModelARX>(wspA, wspB, opoznienie, mocZaklocenia);

    // Kompozyt równoleg³y: ModelARX (model1) || ModelARX (model2)
    auto rownolegleARX = std::make_shared<PetlaRownolegla>(trybPracyPetli::OTWARTA);
    rownolegleARX->DodajSkladnik(model1);
    rownolegleARX->DodajSkladnik(model2);

    // Kompozyt szeregowy: RegulatorPID -> (ModelARX || ModelARX), zamkniêta pêtla
    std::shared_ptr<PetlaUAR> szeregowa = std::make_shared<PetlaSzeregowa>(trybPracyPetli::ZAMKNIETA);
    szeregowa->DodajSkladnik(regulator);
    szeregowa->DodajSkladnik(rownolegleARX);

    // Dodajemy model3 szeregowo na koñcu
    szeregowa->DodajSkladnik(model3);

    // Tworzenie zagnie¿d¿onych dekoratorów sygna³u
    std::unique_ptr<Generator> sygnal = std::make_unique<SygnalTrojkatnyDekorator>(std::make_unique<GeneratorStala>(5.0), 3.0, 15);

    std::vector<double> wejscie(200, 0.0);
    for (size_t k = 0; k < wejscie.size(); ++k) {
        wejscie[k] = sygnal->generuj();
    }

    // Symulacja z model3
    std::vector<double> wyjscie_z_model3(200, 0.0);
    std::cout << "\nSymulacja z dodatkowym modelem szeregowo:\n";
    std::cout << std::setw(4) << "krok"
        << std::setw(10) << "zadana"
        << std::setw(15) << "wyjscie+model3" << std::endl;
    for (size_t k = 0; k < wejscie.size(); ++k) {
        wyjscie_z_model3[k] = szeregowa->symuluj(wejscie[k]);
        std::cout << std::setw(4) << k
            << std::setw(10) << wejscie[k]
            << std::setw(15) << wyjscie_z_model3[k] << std::endl;
    }

#endif // TEST_PETLI


    Interfejs userInterfejs;
    userInterfejs.InterfejsStart();

    return 0;
}
