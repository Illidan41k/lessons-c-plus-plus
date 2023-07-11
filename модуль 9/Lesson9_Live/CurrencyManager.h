#pragma once
#include <vector>
#include <string>

class Cash
{
public:
	enum class CoinsType
	{
		Gold,
		Silver
	};

	struct OneTypeStorage
	{
		CoinsType type;
		size_t count;
	};

	Cash();
	Cash(const CoinsType type, const int count);

	void PrintAllCash();

	Cash operator+=(const Cash &other);
	Cash operator+(const Cash& other);
private:

	void CreateEmptyCashStorage();
	void AddCoins(const OneTypeStorage&);
	void PrintVectorCash(const std::vector<OneTypeStorage>&, const std::string&);

	std::vector<OneTypeStorage> m_summarizedCash{};

	
};

