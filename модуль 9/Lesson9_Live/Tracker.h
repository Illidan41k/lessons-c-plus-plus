#pragma once
#include <vector>
#include <memory>
#include <string>

class Image
{

};

class Timer
{

};

class Tracker
{
public:

	bool ProcessInternal(const Image&) {};

private:
	std::shared_ptr<std::vector<std::string>> m_features{};
	std::shared_ptr<std::vector<int>> m_coordinates{};
	std::shared_ptr<Timer> m_timer{};
	std::shared_ptr<std::vector<Tracker>> m_neighbours{};
};

