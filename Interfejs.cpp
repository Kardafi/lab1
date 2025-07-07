#include "Interfejs.h"

void Interfejs::PokazMenu()
{
	std::cout << "--------------------MENU PROGRAMU-------------------------\n";
	std::cout << "Wybierz opcje: (1-7)\n";
	std::cout << "1. Ustawienia sygnalu\n";
	std::cout << "2. Ustawienia Modelu ARX\n";
	std::cout << "3. Ustawienia Regulatora PID\n";
	std::cout << "4. Uruchom symulacje ukladu\n";
	std::cout << "5. Zapisz konfiguracje do pliku\n";
	std::cout << "6. Wczytaj konfiguracje z pliku\n";
	std::cout << "7. Wyjscie\n";
	std::cout << "----------------------------------------------------------\n";
}

void Interfejs::InterfejsStart()
{
	
	int wybor = 0;

	while (true) {
		PokazMenu();
		std::cout << "Wybierz opcje: ";
		wybor = PobierzWyborUzytkownika();

		switch (wybor) {
		case 1:
			UstawieniaSygnalu();
			break;
		case 2:
			UstawieniaModeluARX();
			break;
		case 3:
			UstawieniaRegulatoraPID();
			break;
		case 4:
			UruchomSymulacjeUkladu();
			break;
		case 5:
			ZapiszKonfiguracjeDoPliku();
			break;
		case 6:
			WczytajKonfiguracjeZPliku();
			break;
		case 7:
			std::cout << "Zamykanie programu...\n";
			return;
		}
	}
}

int Interfejs::PobierzWyborUzytkownika(int liczbaMax)
{
	std::string linia;
	int wybor;

	while (true) {
		std::getline(std::cin, linia);
		std::istringstream iss(linia);

		if (iss >> wybor && (wybor >= 1 && wybor <= liczbaMax) && iss.eof()) {
			// iss.eof() sprawdza, czy NIE MA ju¿ nic wiêcej po liczbie
			return wybor;
		}
		std::cout << "Nieprawidlowy wybor! Wpisz ponownie liczbe: ";
	}
}

double Interfejs::PobierzLiczbeOdUzytkownika()
{
	std::string linia;
	double liczba;

	while (true) {
		std::getline(std::cin, linia);                // Wczytaj ca³y wiersz
		std::istringstream iss(linia);                // Stwórz strumieñ do parsowania

		if (iss >> liczba && iss.eof()) {             // Uda³o siê odczytaæ i nic nie zosta³o
			return liczba;                            // Zwróæ liczbê
		}

		std::cout << "Nieprawidlowa liczba. Prosze sprobowac ponownie: ";
	}
}

void Interfejs::UstawieniaSygnalu()
{
	std::cout << "Ustawienia sygnalu:\n";
	std::unique_ptr<Generator> nowySygnal;

	double poziom = 0.0;
	std::cout << "Podaj poziom sygnalu bazowego:";
	poziom = PobierzLiczbeOdUzytkownika();
	nowySygnal = std::make_unique<GeneratorStala>(poziom);

	while (true) {
		std::cout << "---------------------------------------------\n";
		std::cout << "Dodaj dekorator sygnalu. Wybierz opcje (1-6):\n";
		std::cout << "1. Bialy szum\n";
		std::cout << "2. Sygnal prostokatny\n";
		std::cout << "3. Sygnal sinusoidalny\n";
		std::cout << "4. Sygnal trojkatny\n";
		std::cout << "5. Ograniczenie amplitudy\n";
		std::cout << "6. WYJSCIE do menu glownego\n";
		switch (PobierzWyborUzytkownika(6)) {
			case 1: { // Bialy szum 
				double wartoscBialegoSzumu = 0.0;
				std::cout << "Podaj wartosc bialego szumu: ";
				wartoscBialegoSzumu = PobierzLiczbeOdUzytkownika();
				nowySygnal = std::make_unique<SygnalBialySzum>(std::move(nowySygnal), wartoscBialegoSzumu);
				break;
			}
			case 2: { // Sygna³ prostok¹tny
				double amplitudaProstokatnego = 0.0;
				int okresProstokatnego = 0;
				double wypelnienieProstokatnego = 0.0;
				std::cout << "Podaj amplitude sygnalu prostokatnego: ";
				amplitudaProstokatnego = PobierzLiczbeOdUzytkownika();
				std::cout << "Podaj okres sygnalu prostokatnego (liczba probek): ";
				okresProstokatnego = static_cast<int>(PobierzLiczbeOdUzytkownika());
				std::cout << "Podaj wypelnienie sygnalu prostokatnego (0-1): ";
				wypelnienieProstokatnego = PobierzLiczbeOdUzytkownika();
				nowySygnal = std::make_unique<SygnalProstokatnyDekorator>(std::move(nowySygnal), amplitudaProstokatnego, okresProstokatnego, wypelnienieProstokatnego);
				break;
			}
			case 3: { // Sygna³ sinusoidalny
				double amplitudaSinus = 0.0;
				double czestotliwoscSinus = 0.0;
				double probkowanieSinus = 0.0;
				std::cout << "Podaj amplitude sygnalu sinusoidalnego: ";
				amplitudaSinus = PobierzLiczbeOdUzytkownika();
				std::cout << "Podaj czestotliwosc sygnalu sinusoidalnego (Hz): ";
				czestotliwoscSinus = PobierzLiczbeOdUzytkownika();
				std::cout << "Podaj czestotliwosc probkowania (Hz): ";
				probkowanieSinus = PobierzLiczbeOdUzytkownika();
				nowySygnal = std::make_unique<SygnalSinusDekorator>(std::move(nowySygnal), amplitudaSinus, czestotliwoscSinus, probkowanieSinus);
				break;
			}
			case 4: { // Sygna³ trójk¹tny
				double amplitudaTrojkatnego = 0.0;
				int okresTrojkatnego = 0;
				std::cout << "Podaj amplitude sygnalu trojkatnego: ";
				amplitudaTrojkatnego = PobierzLiczbeOdUzytkownika();
				std::cout << "Podaj okres sygnalu trojkatnego (liczba probek): ";
				okresTrojkatnego = static_cast<int>(PobierzLiczbeOdUzytkownika());
				nowySygnal = std::make_unique<SygnalTrojkatnyDekorator>(std::move(nowySygnal), amplitudaTrojkatnego, okresTrojkatnego);
				break;
			}
			case 5: { // Ograniczenie amplitudy
				double maxAmplituda = 0.0;
				std::cout << "Podaj maksymalna amplitude sygnalu: ";
				maxAmplituda = PobierzLiczbeOdUzytkownika();
				nowySygnal = std::make_unique<OgraniczenieAmplitudyDekorator>(std::move(nowySygnal), maxAmplituda);
				break;
			}
			case 6: { // Wyjœcie do menu g³ównego
				std::cout << "Wracam do menu glownego...\n";
				sygnal = std::move(nowySygnal);
				return;
			}
		}

	}
}

void Interfejs::UstawieniaModeluARX()
{
	std::cout << "Ustawienia Modelu ARX:\n";

	std::cout << "Podaj liczbe wspolczynnikow A (rzad mianownika): ";
	std::vector<double> wspolczynnikiA;
	int liczbaWspolczynnikowA = PobierzLiczbeOdUzytkownika();

	std::cout << "Podaj liczbe wspolczynnikow B (rzad licznika): ";
	std::vector<double> wspolczynnikiB;
	int liczbaWspolczynnikowB = PobierzLiczbeOdUzytkownika();

	std::cout << "Podaj WARTOSCI wspolczynnikow A (mianownik):\n";
	for (int i = 0; i < liczbaWspolczynnikowA; ++i) {
		std::cout << "A[" << i << "]: ";
		double wartosc = PobierzLiczbeOdUzytkownika();
		wspolczynnikiA.push_back(wartosc);
	}

	std::cout << "Podaj WARTOSCI wspolczynnikow B (licznik):\n";
	for (int i = 0; i < liczbaWspolczynnikowB; ++i) {
		std::cout << "B[" << i << "]: ";
		double wartosc = PobierzLiczbeOdUzytkownika();
		wspolczynnikiB.push_back(wartosc);
	}

	unsigned int opoznienie = 0;
	double mocSzumu = 0;

	// Pêtla: wczytaj poprawne opóŸnienie
	while (true) {
		std::cout << "Podaj czas opoznienia (liczba probek, >= 0): ";
		double wartosc = PobierzLiczbeOdUzytkownika();

		if (wartosc >= 0 && wartosc == static_cast<unsigned int>(wartosc)) {
			opoznienie = static_cast<unsigned int>(wartosc);
			break;
		}
		else {
			std::cout << "Blad: czas opoznienia musi byc liczba calkowita >= 0.\n";
		}
	}

	// Pêtla: wczytaj poprawn¹ moc szumu
	while (true) {
		std::cout << "Podaj moc szumu (>= 0, 0 = brak szumu): ";
		double wartosc = PobierzLiczbeOdUzytkownika();

		if (wartosc >= 0) {
			mocSzumu = wartosc;
			break;
		}
		else {
			std::cout << "Blad: moc szumu musi byc liczba >= 0.\n";
		}
	}

	std::cout << "Tworzenie modelu ARX...\n";
	modelARX = std::make_shared<ModelARX>(wspolczynnikiA, wspolczynnikiB, opoznienie, mocSzumu);
	std::cout << "Wracam do menu glownego...\n";
}

void Interfejs::UstawieniaRegulatoraPID()
{
	std::cout << "Ustawienia Regulatora PID:\n";

	double k = 0.0, ti = 0.0, td = 0.0;

	//wczytaj poprawne k (wzmocnienie > 0)
	while (true) {
		std::cout << "Podaj wzmocnienie k (> 0): ";
		k = PobierzLiczbeOdUzytkownika();
		if (k > 0.0) break;
		std::cout << "Blad: wzmocnienie k musi byc wieksze od zera.\n";
	}

	// Ti i Td mog¹ byæ równe 0
	std::cout << "Podaj czas calkowania Ti (>= 0): ";
	ti = PobierzLiczbeOdUzytkownika();

	std::cout << "Podaj czas rozniczkowania Td (>= 0): ";
	td = PobierzLiczbeOdUzytkownika();

	regulatorPID = std::make_shared<RegulatorPID>(k, ti, td);

	std::cout << "Regulator PID zostal ustawiony.\n";
	std::cout << "Wracam do menu glownego...\n";
}

void Interfejs::UruchomSymulacjeUkladu()
{
	std::cout << "Uruchamianie symulacji ukladu...\n";
	if (!sygnal) {
		std::cout << "Brak sygnalu do symulacji. Ustaw sygnal w menu.\n";
		return;
	}
	if (!modelARX) {
		std::cout << "Brak modelu ARX do symulacji. Ustaw model w menu.\n";
		return;
	}
	if (!regulatorPID) {
		std::cout << "Brak regulatora PID do symulacji. Ustaw regulator w menu.\n";
		return;
	}

	std::cout << "Podaj liczbe probek symulacji: ";
	int liczbaProbek = 0;
	while (true) {
		liczbaProbek = static_cast<int>(PobierzLiczbeOdUzytkownika());
		if (liczbaProbek > 0) break;
		std::cout << "Liczba probek musi byc wieksza od zera. Podaj ponownie: ";
	}

	std::vector<double> wartosciWejsciowe(liczbaProbek,0.0);
	std::vector<double> wartosciWyjsciowe(liczbaProbek, 0.0);
	//generowanie sygna³u
	for (int i = 0;i < liczbaProbek;i++) {
		wartosciWejsciowe[i] = sygnal->generuj();
	}

	//petla zamknieta, regulator -> model
	double poprzedniaWartosc = 0.0;
	for (int i = 0; i < liczbaProbek; ++i) {
		double uchyb = wartosciWejsciowe[i] - poprzedniaWartosc;

		double wartoscRegulatora = regulatorPID->symuluj(uchyb);

		wartosciWyjsciowe[i] = modelARX->symuluj(wartoscRegulatora);

		poprzedniaWartosc = wartosciWyjsciowe[i];
	}

	std::cout << "Symulacja zakonczona. Wyniki:\n";
	for (int i = 0; i < liczbaProbek; ++i) {
		std::cout << "Probka " << i + 1 << "| Wejscie = " << wartosciWejsciowe[i]
			<< ", Wyjscie = " << wartosciWyjsciowe[i] << "\n";
	}

	std::cout << "Wracam do menu glownego...\n";
}

void Interfejs::ZapiszKonfiguracjeDoPliku()
{
	if (!sygnal && !modelARX && !regulatorPID) {
		std::cout << "Brak ustawien do zapisania.\n";
		return;
	}

	std::cout << "Zapis konfiguracji do pliku...\n";
	std::cout << "Podaj nazwe pliku do zapisu (domyslnie 'konfiguracja.txt'): ";

	std::string nazwaPliku;
	std::getline(std::cin, nazwaPliku);

	if (nazwaPliku.empty()) {
		nazwaPliku = "konfiguracja.txt";
	}

	std::ofstream out(nazwaPliku);

	if (!out.is_open()) {
		std::cerr << "Nie mozna otworzyc pliku do zapisu.\n";
		return;
	}
	if (sygnal) {
		sygnal->serialize(out);
		std::cout << "Zapisano sygnal do pliku.\n";
	}
	if (modelARX) {
		modelARX->serialize(out);
		std::cout << "Zapisano model ARX do pliku.\n";
	}
	if (regulatorPID) {
		regulatorPID->serialize(out);
		std::cout << "Zapisano regulator PID do pliku.\n";
	}
	out.close();

	std::cout << "Konfiguracja zapisana do pliku " + nazwaPliku + ".\n";
}

void Interfejs::WczytajKonfiguracjeZPliku()
{
	std::cout << "Podaj nazwe pliku: (domyslnie 'konfiguracja.txt')\n";

	std::string nazwaPliku;
	std::getline(std::cin, nazwaPliku);

	if (nazwaPliku.empty()) {
		nazwaPliku = "konfiguracja.txt";
	}
	std::ifstream plikWejsciowy(nazwaPliku);
	sygnal = std::move(DeserializujSygnal(plikWejsciowy));
	plikWejsciowy.close();
	plikWejsciowy.open(nazwaPliku);
	modelARX = std::move(DeserializujModel(plikWejsciowy));
	plikWejsciowy.close();
	plikWejsciowy.open(nazwaPliku);
	regulatorPID = std::move(DeserializujRegulator(plikWejsciowy));
}

std::unique_ptr<Generator> Interfejs::DeserializujSygnal(std::ifstream& in)
{
	std::string linia;
	std::unique_ptr<Generator> nowySygnal = nullptr;

	std::cout << "Wczytywanie sygnalu z pliku...\n";

	while (std::getline(in, linia)) {
		// Pomijamy puste linie
		if (linia.empty()) continue;

		// Szukamy typu obiektu
		if (linia.find("\"typ\"") != std::string::npos) {
			std::string typ;
			size_t start = linia.find("\"", linia.find(":")) + 1;
			size_t end = linia.find("\"", start);
			typ = linia.substr(start, end - start);
			if (typ != "ModelARX" && typ != "RegulatorPID") {

				// Parsujemy sekcjê "dane"
				std::map<std::string, double> dane;
				std::getline(in, linia);//pomijamy linie z tekstem: "dane"
				while (std::getline(in, linia) && linia.find("}") == std::string::npos) {
					size_t keyStart = linia.find("\"");
					if (keyStart == std::string::npos) continue;

					size_t keyEnd = linia.find("\"", keyStart + 1);
					std::string klucz = linia.substr(keyStart + 1, keyEnd - keyStart - 1);

					size_t valStart = linia.find(":", keyEnd);
					if (valStart != std::string::npos) {
						std::string wartoscTemp = linia.substr(valStart + 1);
						//usuñ spacje na pocz¹tku i koñcu
						wartoscTemp.erase(0, wartoscTemp.find_first_not_of(" \t\n\r"));
						wartoscTemp.erase(wartoscTemp.find_last_not_of(" \t\n\r") + 1);

						//czy koñczy siê przecinkiem i usuñ go
						if (!wartoscTemp.empty() && wartoscTemp.back() == ',') {
							wartoscTemp.pop_back();

							//usuñ te¿ spacje po usuniêciu przecinka
							wartoscTemp.erase(wartoscTemp.find_last_not_of(" \t\n\r") + 1);
						}
						double wartosc = std::stod(wartoscTemp);
						dane[klucz] = wartosc;
					}
				}
			

				// Tworzymy odpowiedni obiekt
				if (typ == "GeneratorStala") {
					nowySygnal = std::make_unique<GeneratorStala>(dane["wartosc"]);
					std::cout << "Sygnal bazowy o wartosci " << dane["wartosc"] << " zostal utworzony.\n";
				}
				else if (typ == "SygnalBialySzum") {
					nowySygnal = std::make_unique<SygnalBialySzum>(std::move(nowySygnal), dane["amplituda"]);
					std::cout << "Sygnal bialy szum o amplitudzie " << dane["amplituda"] << " zostal utworzony.\n";
				}
				else if (typ == "SygnalProstokatny") {
					nowySygnal = std::make_unique<SygnalProstokatnyDekorator>(
						std::move(nowySygnal),
						dane["amplituda"],
						static_cast<int>(dane["okres"]),
						dane["wypelnienie"]
					);
					std::cout << "Sygnal prostokatny o amplitudzie " << dane["amplituda"]
						<< ", okresie " << static_cast<int>(dane["okres"])
						<< " i wypelnieniu " << dane["wypelnienie"] << " zostal utworzony.\n";
				}
				else if (typ == "SygnalSinusoidalny") {
					nowySygnal = std::make_unique<SygnalSinusDekorator>(
						std::move(nowySygnal),
						dane["amplituda"],
						dane["czestotliwosc"],
						dane["probkowanie"]
					);
					std::cout << "Sygnal sinusoidalny o amplitudzie " << dane["amplituda"]
						<< ", czestotliwosci " << dane["czestotliwosc"]
						<< " i probkowaniu " << dane["probkowanie"] << " zostal utworzony.\n";
				}
				else if (typ == "SygnalTrojkatny") {
					nowySygnal = std::make_unique<SygnalTrojkatnyDekorator>(
						std::move(nowySygnal),
						dane["amplituda"],
						static_cast<int>(dane["okres"])
					);
					std::cout << "Sygnal trojkatny o amplitudzie " << dane["amplituda"]
						<< " i okresie " << static_cast<int>(dane["okres"]) << " zostal utworzony.\n";
				}
				else if (typ == "OgraniczenieAmplitudy") {
					nowySygnal = std::make_unique<OgraniczenieAmplitudyDekorator>(
						std::move(nowySygnal),
						dane["wartoscMaksymalna"]
					);
					std::cout << "Ograniczenie amplitudy do " << dane["wartoscMaksymalna"] << " zostalo utworzone.\n";
				}
			}
		}
	}

	return nowySygnal;
}

std::shared_ptr<ModelARX> Interfejs::DeserializujModel(std::ifstream& in)
{	
	return ModelARX::deserialize(in);
}

std::shared_ptr<RegulatorPID> Interfejs::DeserializujRegulator(std::ifstream& in)
{
	return RegulatorPID::deserialize(in);
}
