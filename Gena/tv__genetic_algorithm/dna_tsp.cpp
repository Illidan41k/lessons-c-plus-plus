
#include "dna_tsp.hpp"
#include <algorithm>

DNA_TSP::DNA_TSP(
	const vector<double>& routeLocationsX,
	const vector<double>& routeLocationsY,
	double routeLength)
{
	_locationsX = &routeLocationsX;
	_locationsY = &routeLocationsY;
	_routeLength = routeLength;

	_genes.resize(routeLocationsX.size());
	std::iota(_genes.begin(), _genes.end(), 0);

	_fitness = std::numeric_limits<double>::max();

	auto xMax = std::max_element(_locationsX->begin(), _locationsX->end());
	auto yMax = std::max_element(_locationsY->begin(), _locationsY->end());

	_imageTemplate = cv::Mat::zeros(*yMax, *xMax, CV_8UC3);

	for (size_t i = 0; i < routeLocationsX.size(); i++)
	{
		circle(_imageTemplate, Point(routeLocationsX[i], routeLocationsY[i]), 6, cv::Scalar(100, 200, 0), FILLED);
	}
}


DNA_TSP::DNA_TSP(const DNA_TSP& copyFrom)
{
	_locationsX = copyFrom._locationsX;
	_locationsY = copyFrom._locationsY;
	_routeLength = copyFrom._routeLength;
	_fitness = copyFrom._fitness;
	copyGenes(copyFrom);

	auto xMax = std::max_element(_locationsX->begin(), _locationsX->end());
	auto yMax = std::max_element(_locationsY->begin(), _locationsY->end());

	_imageTemplate = cv::Mat::zeros(*yMax, *xMax, CV_8UC3);

	for (size_t i = 0; i < _locationsX->size(); i++)
	{
		circle(_imageTemplate, Point(_locationsX->at(i), _locationsY->at(i)), 6, cv::Scalar(100, 200, 0), FILLED);
	}
}


DNA_TSP& DNA_TSP::operator = (const DNA_TSP& copyFrom)
{
	_locationsX = copyFrom._locationsX;
	_locationsY = copyFrom._locationsY;
	_routeLength = copyFrom._routeLength;
	_fitness = copyFrom._fitness;
	copyGenes(copyFrom);

	return *this;
}


DNA_TSP::~DNA_TSP()
{
}


void DNA_TSP::initGenesWithRandomValues()
{
	// Randomly shuffle the genes (route indices).

	size_t iGeneSwap = 0;
	size_t geneTemp = 0;

	for (size_t iGene = 0; iGene < _genes.size(); iGene++)
	{
		iGeneSwap = getRandomIntegerInRange<size_t>(0, _genes.size() - 1);

		geneTemp = _genes[iGene];
		_genes[iGene] = _genes[iGeneSwap];
		_genes[iGeneSwap] = geneTemp;
	}
}


void DNA_TSP::copyGenes(const DNA_TSP& copyFrom)
{
	_genes.resize(_locationsX->size());

	for (size_t iGene = 0; iGene < _genes.size(); iGene++)
		_genes[iGene] = copyFrom._genes[iGene];
}


void DNA_TSP::recombineGenes(
	const DNA_TSP& parent1,
	const DNA_TSP& parent2)
{
	orderCrossover_OX(parent1, parent2);
}


void DNA_TSP::mutateGenes(double probability)
{
	if (getRandomTrueWithProbability(probability))
		swapMutation();

	twoOptLocalSearch();
}

void DNA_TSP::draw()
{
	auto copy = _imageTemplate.clone();

	for (size_t i = 0; i < _genes.size() - 1; i++)
	{
		cv::line(copy, Point(_locationsX->at(_genes[i]), _locationsY->at(_genes[i])), Point(_locationsX->at(_genes[i + 1]), _locationsY->at(_genes[i + 1])), Scalar(100, 0, 220), 2);
	}
	resize(copy, copy, Size(), 0.7, 0.7);
	imshow("current best solution", copy);
	waitKey();
}


double DNA_TSP::calcFitness()
{


	_fitness = calcRouteLength(_genes);

	return _fitness;
}


double DNA_TSP::getFitness() const
{
	return _fitness;
}


string DNA_TSP::toString() const
{
	// This returns a string of all route locations which are represented
	// as indices of the coordinate arrays. The route is a loop and will be
	// shifted to always display index 0 as the first route location.
	//
	// The standard string has a move constructor, so returning long strings
	// by value is efficient.

	// Find the start of the route.

	size_t iRouteStart = 0;

	for (size_t iGene = 0; iGene < _genes.size(); iGene++)
		if (_genes[iGene] == 0)
		{
			iRouteStart = iGene;
			break;
		}

	// Get the elements from the route start index to the end of the array.

	string dnaStr = "[";

	for (size_t iGene = iRouteStart; iGene < _genes.size(); iGene++)
	{
		if (_genes[iGene] < 10)
			dnaStr += " ";

		dnaStr += std::to_string(_genes[iGene]) + ", ";
	}

	// Get the elements from the start of the array to the route start index.

	for (size_t iGene = 0; iGene < iRouteStart; iGene++)
	{
		if (_genes[iGene] < 10)
			dnaStr += " ";

		dnaStr += std::to_string(_genes[iGene]) + ", ";
	}

	return dnaStr + "]";
}


bool DNA_TSP::isSolved() const
{
	return _fitness < _routeLength;
}


inline double DNA_TSP::calcRouteLength(const vector<size_t>& route)
{
	// This calculates the sum of all distances between successive
	// route locations.

	double totalLength = 0.0;

	for (size_t i = 0; i < route.size() - 1; i++)
		totalLength += euclidianDistance2D(
			_locationsX->at(route[i]),
			_locationsY->at(route[i]),
			_locationsX->at(route[i + 1]),
			_locationsY->at(route[i + 1]));

	// Add the distance from the last to the first route location.

	totalLength += euclidianDistance2D(
		_locationsX->at(route[route.size() - 1]),
		_locationsY->at(route[route.size() - 1]),
		_locationsX->at(route[0]),
		_locationsY->at(route[0]));

	return totalLength;
}


inline double DNA_TSP::euclidianDistance2D(
	double x1,
	double y1,
	double x2,
	double y2)
{
	return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}


inline void DNA_TSP::orderCrossover_OX(
	const DNA_TSP& dna1,
	const DNA_TSP& dna2)
{

	size_t iSecStart = 0;
	size_t iSecEnd = 0;

	while (iSecStart >= iSecEnd)
	{
		iSecStart = getRandomIntegerInRange<size_t>(0, dna1._genes.size() - 1);
		iSecEnd = getRandomIntegerInRange<size_t>(0, dna1._genes.size() - 1);
	}


	for (size_t iGene = iSecStart; iGene <= iSecEnd; iGene++)
		_genes[iGene] = dna1._genes[iGene];

	const size_t sectionSize = iSecEnd - iSecStart;


	vector<size_t> dnaDifference;
	dnaDifference.reserve(dna2._genes.size() - sectionSize);

	if (iSecEnd + 1 <= dna2._genes.size() - 1)
		for (size_t iGene = iSecEnd + 1; iGene < dna2._genes.size(); iGene++)
			if (!isGeneInSection(dna2._genes[iGene], iSecStart, iSecEnd))
				dnaDifference.push_back(dna2._genes[iGene]);

	for (size_t iGene = 0; iGene <= iSecEnd; iGene++)
		if (!isGeneInSection(dna2._genes[iGene], iSecStart, iSecEnd))
			dnaDifference.push_back(dna2._genes[iGene]);

	size_t i = 0;

	if (iSecEnd + 1 <= dna2._genes.size() - 1)
		i = iSecEnd + 1;

	for (size_t iGene = 0; iGene < dnaDifference.size(); iGene++)
	{
		_genes[i] = dnaDifference[iGene];
		i++;
		if (i > _genes.size() - 1)
			i = 0;
	}
}


inline bool DNA_TSP::isGeneInSection(
	size_t gene,
	size_t iSectionStart,
	size_t iSectionEnd) const
{
	for (size_t iGene = iSectionStart; iGene <= iSectionEnd; iGene++)
		if (gene == _genes[iGene])
			return true;

	return false;
}


inline void DNA_TSP::swapMutation()
{
	const auto iGene1 = getRandomIntegerInRange<size_t>(0, _genes.size() - 1);
	const auto iGene2 = getRandomIntegerInRange<size_t>(0, _genes.size() - 1);

	const auto tempGene = _genes[iGene1];
	_genes[iGene1] = _genes[iGene2];
	_genes[iGene2] = tempGene;
}


inline void DNA_TSP::twoOptLocalSearch()
{
	bool hasImproved = true;
	double swappedGenesFitness = 0.0;
	vector<size_t> swappedGenes(_genes.size());

	while (hasImproved)
	{
		for (size_t iGene1 = 1; iGene1 < _genes.size() - 1; iGene1++)
			for (size_t iGene2 = iGene1 + 1; iGene2 < _genes.size(); iGene2++)
			{
				twoOptSwap(_genes, swappedGenes, iGene1, iGene2);
				swappedGenesFitness = calcRouteLength(swappedGenes);

				if (swappedGenesFitness < _fitness)
				{
					_genes.swap(swappedGenes);
					_fitness = swappedGenesFitness;
					hasImproved = true;
				}
				else { hasImproved = false; }
			}
	}
}


inline void DNA_TSP::twoOptSwap(
	const vector<size_t>& inGenes,
	vector<size_t>& outGenes,
	size_t iGene1,
	size_t iGene2)
{
	for (size_t iGene = 0; iGene <= iGene1 - 1; iGene++)
		outGenes[iGene] = inGenes[iGene];


	size_t iter = 0;
	for (size_t iGene = iGene1; iGene <= iGene2; iGene++)
	{
		outGenes[iGene] = inGenes[iGene2 - iter];
		iter++;
	}


	for (size_t iGene = iGene2 + 1; iGene < inGenes.size(); iGene++)
		outGenes[iGene] = inGenes[iGene];
}

