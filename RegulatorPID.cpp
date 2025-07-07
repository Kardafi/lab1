#include "RegulatorPID.h"


RegulatorPID::RegulatorPID(double _k) : k(_k)
{
	Ti = 0;
	Td = 0;
}

RegulatorPID::RegulatorPID(double _k, double _Ti) : k(_k), Ti(_Ti)
{
	Td = 0;
}

RegulatorPID::RegulatorPID(double _k, double _Ti, double _Td) : k(_k), Ti(_Ti), Td(_Td)
{
}

RegulatorPID::~RegulatorPID()
{
}

double RegulatorPID::symuluj(double wejscie)
{
	pamiecUchyl.push_back(wejscie);
	double wynik = k * wejscie;

	if (Ti > 0) { //PI
		double suma = 0;
		for (auto elem : pamiecUchyl) {
			suma += elem;
		}

		wynik += (1 / Ti) * suma;
	}
	if (Td > 0) { //PID
		if (pamiecUchyl.size() >= 2) {
			wynik += Td * (pamiecUchyl.back() - pamiecUchyl.at(pamiecUchyl.size() - 2));
		}

	}

	return wynik;
}

void RegulatorPID::setK(double _k)
{
	if (SprawdzNastawe(_k))
		k = _k;
	else
		std::cerr << "Blad! Niepoprawna wartosc k!";
}

void RegulatorPID::setTi(double _Ti)
{
	if (SprawdzNastawe(_Ti))
		Ti = _Ti;
	else
		std::cerr << "Blad! Niepoprawna wartosc Ti!";
}

void RegulatorPID::setTd(double _Td)
{
	if (SprawdzNastawe(_Td))
		Td = _Td;
	else
		std::cerr << "Blad! Niepoprawna wartosc Td!";
}

void RegulatorPID::serialize(std::ostream& out) const {
	out << "{\n";
	out << "  \"typ\": \"RegulatorPID\",\n";
	out << "  \"dane\": {\n";
	out << "    \"k\": " << k << ",\n";
	out << "    \"Ti\": " << Ti << ",\n";
	out << "    \"Td\": " << Td << "\n";
	out << "  }\n";
	out << "}\n";
}

std::shared_ptr<RegulatorPID> RegulatorPID::deserialize(std::istream& in) {
	double k = 0.0, Ti = 0.0, Td = 0.0;
	std::string line;
	bool inDane = false;

	std::cout << "Wczytywanie regulatora PID z pliku...\n";

	while (std::getline(in, line)) {
		std::string clean = line;
		clean.erase(std::remove_if(clean.begin(), clean.end(), ::isspace), clean.end());

		if (clean.find("\"dane\":{") != std::string::npos)
			inDane = true;

		else if (inDane && clean.find("\"k\":") != std::string::npos) {
			k = std::stod(line.substr(line.find(":") + 1));
			std::cout << "Wczytano k: " << k << "\n";
		}

		else if (inDane && clean.find("\"Ti\":") != std::string::npos) {
			Ti = std::stod(line.substr(line.find(":") + 1));
			std::cout << "Wczytano Ti: " << Ti << "\n";
		}

		else if (inDane && clean.find("\"Td\":") != std::string::npos) {
			Td = std::stod(line.substr(line.find(":") + 1));
			std::cout << "Wczytano Td: " << Td << "\n";
		}
	}

	if (Ti > 0 && Td > 0) {
		return std::make_shared<RegulatorPID>(k, Ti, Td);
	}
	else if (Ti > 0) {
		return std::make_shared<RegulatorPID>(k, Ti);
	}
	else {
		return std::make_shared<RegulatorPID>(k);
	}
}



int RegulatorPID::SprawdzNastawe(double _nastawa)
{
	if (_nastawa > 0) return 1;
	else return 0;
}
