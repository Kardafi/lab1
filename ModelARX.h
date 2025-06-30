#pragma once
#include "ObiektSISO.h"
#include <vector>
#include <deque>
#include <random>


/// <summary>
/// Klasa reprezentuj�ca dyskretny model ARX, dziedzicz�ca po abstrakcyjnym obiekcie SISO.
/// 
/// Model opisuje zale�no�� sygna�u wyj�ciowego od wcze�niejszych warto�ci wej�� i wyj��,
/// z uwzgl�dnieniem czasu op�nienia oraz opcjonalnym dodawaniem szumu.
/// </summary>
class ModelARX : public ObiektSISO {
private:
	std::vector<double> A; //parametry wielomianu -> A (mianownik) i B (licznik)
	std::vector<double> B;
	std::deque<double> pamiecWejscie; //pamie� sygna��w wej�ciowych
	std::deque<double> pamiecWyjscie; //pamie� sygna��w wyj�ciowych

	unsigned int opoznienie; //dyskretny czas op�nienia

	double mocSzumu;
	std::default_random_engine generator;
	std::normal_distribution<double>* rozkladSzumu;

	/// <summary>
	/// Dodaje losowy szum do sygna�u wyj�ciowego na podstawie ustalonej mocy szumu.
	/// </summary>
	/// returns>Warto�� szumu.</returns>
	double dodajSzum();

public:

	/// <summary>
	/// Konstruktor inicjalizuj�cy model na podstawie wsp�czynnik�w A, B, op�nienia i mocy szumu.
	/// </summary>
	/// param name="_A">Wsp�czynniki A (mianownik).</param>
	/// param name="_B">Wsp�czynniki B (licznik).</param>
	/// param name="_k">Dyskretny czas op�nienia.</param>
	/// param name="_mocSzumu">Moc szumu .</param>
	ModelARX(const std::vector<double>& _A, const std::vector<double>& _B, unsigned int _k, int _mocSzumu);

	/// <summary>
	/// Konstruktor inicjalizuj�cy model na podstawie danych zapisanych w pliku.
	/// </summary>
	/// param name="sciezkaPliku">�cie�ka do pliku z danymi modelu.</param>
	ModelARX(const std::string& sciezkaPliku);

	~ModelARX();

	/// <summary>
	/// Zapisuje parametry modelu ARX do pliku w formacie pseudo-JSON.
	/// </summary>
	/// <param name="filename">Nazwa pliku, do kt�rego zostan� zapisane parametry.</param>
	void ZapiszDoPlikuJSON(const std::string& filename) const;

	/// <summary>
	/// Symuluje odpowied� modelu na podstawie nowego wej�cia.
	/// </summary>
	/// <param name="wejscie">Nowa warto�� sygna�u wej�ciowego.</param>
	/// <returns>Wygenerowana warto�� sygna�u wyj�ciowego.</returns>
	double symuluj(double wejscie) override;

	void serialize(std::ofstream& out) const;

	static std::shared_ptr<ModelARX> deserialize(std::istream& in);
};
