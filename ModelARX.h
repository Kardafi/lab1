#pragma once
#include "ObiektSISO.h"
#include <vector>
#include <deque>
#include <random>


/// <summary>
/// Klasa reprezentuj¹ca dyskretny model ARX, dziedzicz¹ca po abstrakcyjnym obiekcie SISO.
/// 
/// Model opisuje zale¿noœæ sygna³u wyjœciowego od wczeœniejszych wartoœci wejœæ i wyjœæ,
/// z uwzglêdnieniem czasu opóŸnienia oraz opcjonalnym dodawaniem szumu.
/// </summary>
class ModelARX : public ObiektSISO {
private:
	std::vector<double> A; //parametry wielomianu -> A (mianownik) i B (licznik)
	std::vector<double> B;
	std::deque<double> pamiecWejscie; //pamieæ sygna³ów wejœciowych
	std::deque<double> pamiecWyjscie; //pamieæ sygna³ów wyjœciowych

	unsigned int opoznienie; //dyskretny czas opóŸnienia

	double mocSzumu;
	std::default_random_engine generator;
	std::normal_distribution<double>* rozkladSzumu;

	/// <summary>
	/// Dodaje losowy szum do sygna³u wyjœciowego na podstawie ustalonej mocy szumu.
	/// </summary>
	/// returns>Wartoœæ szumu.</returns>
	double dodajSzum();

public:

	/// <summary>
	/// Konstruktor inicjalizuj¹cy model na podstawie wspó³czynników A, B, opóŸnienia i mocy szumu.
	/// </summary>
	/// param name="_A">Wspó³czynniki A (mianownik).</param>
	/// param name="_B">Wspó³czynniki B (licznik).</param>
	/// param name="_k">Dyskretny czas opóŸnienia.</param>
	/// param name="_mocSzumu">Moc szumu .</param>
	ModelARX(const std::vector<double>& _A, const std::vector<double>& _B, unsigned int _k, int _mocSzumu);

	/// <summary>
	/// Konstruktor inicjalizuj¹cy model na podstawie danych zapisanych w pliku.
	/// </summary>
	/// param name="sciezkaPliku">Œcie¿ka do pliku z danymi modelu.</param>
	ModelARX(const std::string& sciezkaPliku);

	~ModelARX();

	/// <summary>
	/// Zapisuje parametry modelu ARX do pliku w formacie pseudo-JSON.
	/// </summary>
	/// <param name="filename">Nazwa pliku, do którego zostan¹ zapisane parametry.</param>
	void ZapiszDoPlikuJSON(const std::string& filename) const;

	/// <summary>
	/// Symuluje odpowiedŸ modelu na podstawie nowego wejœcia.
	/// </summary>
	/// <param name="wejscie">Nowa wartoœæ sygna³u wejœciowego.</param>
	/// <returns>Wygenerowana wartoœæ sygna³u wyjœciowego.</returns>
	double symuluj(double wejscie) override;

	void serialize(std::ofstream& out) const;

	static std::shared_ptr<ModelARX> deserialize(std::istream& in);
};
