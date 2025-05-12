#include <iostream>
#include "Generator.h"
#include "GeneratorStala.h"
#include "GeneratorDekorator.h"
#include "SygnalSinusDekorator.h"
#include "SygnalProstokatnyDekorator.h"
#include "SygnalTrojkatnyDekorator.h"
#include "OgraniczenieAmplitudyDekorator.h"
#include "SygnalBialySzum.h"


#define dsadassss

#ifdef MAIN3

int main() {

	GeneratorStala baza(0.0);
	SygnalBialySzum szum(baza, 0.0);
	SygnalTrojkatnyDekorator trojkat(szum, 0.0, 30);
	SygnalSinusDekorator sinus(trojkat, 0.0, 10, 0.5);
	SygnalProstokatnyDekorator prostokat(sinus, 5.0, 10, 0.5);
	OgraniczenieAmplitudyDekorator ograniczenie(prostokat, 10.0);

    for (int i = 0; i < 100; ++i) {
        std::cout << ograniczenie.generuj() << std::endl;
    }


    return 0;
}

#endif // MAIN3