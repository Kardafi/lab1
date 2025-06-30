#include <iostream>
#include <fstream>
#include "ModelARX.h"
#include "RegulatorPID.h"

#include "GeneratorStala.h"
#include "SygnalSinusDekorator.h"
#include "SygnalProstokatnyDekorator.h"
#include "SygnalTrojkatnyDekorator.h"
#include "SygnalBialySzum.h"
#include "OgraniczenieAmplitudyDekorator.h"

int main() {

	//ModelARX model1({ 1.0, 0.5 }, { 0.0, 1.0 }, 2, 10);
	//std::ofstream out("pliki/model1_test.txt");
	//model1.serialize(out);
	//out.close();

	//std::ifstream in("pliki/model1_test.txt");
	//std::shared_ptr<ModelARX> arx1= ModelARX::deserialize(in);
	//std::cout << "test";

	////-----------------------

	//RegulatorPID reg(0.5, 10.0, 0.2);
	//std::ofstream out2("pliki/pid1_test.txt");
	//reg.serialize(out2);
	//out2.close();

	//std::ifstream in2("pliki/pid1_test.txt");
	//std::shared_ptr<RegulatorPID> nowy = RegulatorPID::deserialize(in2);
	//std::cout << "test2";

        // Utwórz podstawowy generator sta³ej
    auto generatorStala = std::make_unique<GeneratorStala>(1.5);

    // Na³ó¿ dekoratory
    auto* sinus = new SygnalSinusDekorator(*generatorStala, 2.0, 10.0, 100.0);
    auto* prostokatny = new SygnalProstokatnyDekorator(*sinus, 3.0, 50, 0.5);
    auto* trojkatny = new SygnalTrojkatnyDekorator(*prostokatny, 1.5, 40);
    auto* szum = new SygnalBialySzum(*trojkatny, 0.2);
    auto* ograniczony = new OgraniczenieAmplitudyDekorator(*szum, 5.0);

    // Serializacja
    std::ofstream out("pliki/test1_caly.txt");
    if (!out.is_open()) {
        std::cerr << "Nie mo¿na otworzyæ pliku do zapisu.\n";
        return 1;
    }

    //out << "[\n";
    generatorStala->serialize(out);// out << ",\n";
    sinus->serialize(out);         // out << ",\n";
    prostokatny->serialize(out);   // out << ",\n";
    trojkatny->serialize(out);    //  out << ",\n";
    szum->serialize(out);         //  out << ",\n";
    ograniczony->serialize(out);//out << "\n";
    //out << "]\n";

    out.close();

    std::cout << "Zserializowano sygna³ do pliku 'sygnal.json'.\n";

    // Sprz¹tanie (bo dekoratory by³y tworzone dynamicznie)
    delete ograniczony;
    delete szum;
    delete trojkatny;
    delete prostokatny;
    delete sinus;

    return 0;
}
