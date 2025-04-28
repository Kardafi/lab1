#include <iostream>
#include "Generator.h"
#include "GeneratorStala.h"
#include "GeneratorDekorator.h"
#include "SygnalSinusDekorator.h"
#include "SygnalProstokatnyDekorator.h"


#define MAIN3

#ifdef MAIN3

int main() {
    GeneratorStala baza(0.0);
    SygnalSinusDekorator sinus(baza, 1.0, 5.0);
    SygnalProstokatnyDekorator prostokat(sinus, 2.0, 10.0, 50.0);

    for (int i = 0; i < 40; ++i) {
        std::cout << prostokat.generuj() << std::endl;
    }

 /*   for (int i = 0; i < 20; ++i) {
        std::cout << sinus.generuj() << std::endl;
    }*/


    return 0;
}

#endif // MAIN3