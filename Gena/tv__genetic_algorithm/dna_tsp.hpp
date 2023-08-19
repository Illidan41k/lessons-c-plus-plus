#pragma once

#include <algorithm>
#include <numeric>

#include <array>
using std::array;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <cmath>
using std::sqrt;
using std::pow;

#include "randnumgen.hpp"
#include "opencv2/opencv.hpp"
using namespace cv;

class DNA_TSP
{
// Methods to be called by the GeneticAlgorithm class:
public:

    DNA_TSP(
        const vector<double>& routeLocationsX,
        const vector<double>& routeLocationsY,
        double routeLength = 0.0);

    DNA_TSP(const DNA_TSP& copyFrom);
    DNA_TSP& operator = (const DNA_TSP& copyFrom);
   ~DNA_TSP();

    void initGenesWithRandomValues();
    void copyGenes(const DNA_TSP& copyFrom);
    void recombineGenes(const DNA_TSP& parent1, const DNA_TSP& parent2);
    void mutateGenes(double probability);
    void draw();
    double calcFitness();
    double getFitness() const;

    string toString() const;

    bool isSolved() const;


// Specific methods and properties for a Travelling Salesman Problem:
private:

    inline double calcRouteLength(const vector<size_t>& route);

    inline double euclidianDistance2D(
        double x1,
        double y1,
        double x2,
        double y2);

    inline void orderCrossover_OX(const DNA_TSP& dna1, const DNA_TSP& dna2);

    inline bool isGeneInSection(
        size_t gene,
        size_t iSectionStart,
        size_t iSectionEnd) const;

    inline void swapMutation();

    inline void twoOptLocalSearch();

    inline void twoOptSwap(
        const vector<size_t>& inGenes,
        vector<size_t>& outGenes,
        size_t iGene1,
        size_t iGene2);

private:
    const vector<double>* _locationsX;
    const vector<double>* _locationsY;
    double _routeLength;

    vector<size_t> _genes;
    double _fitness;

    Mat _imageTemplate;
};
