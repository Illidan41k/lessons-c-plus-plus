
// Copyright (C) by Tim Völcker. All rights reserved.

#include "dna_string_search.hpp"


DNA_StringSearch::DNA_StringSearch(const string& findThisString, const string& alphabet)
{
    _optimalGenes = &findThisString;
    _geneAlphabet = &alphabet;

    _genes.resize(_optimalGenes->size());

    // The objective is to minimize the fitness.
    // The fitness will be initialized with the worst possible value.
    _fitness = std::numeric_limits<double>::max();
}


DNA_StringSearch::DNA_StringSearch(const DNA_StringSearch& copyFrom)
{
    _optimalGenes = copyFrom._optimalGenes;
    _geneAlphabet = copyFrom._geneAlphabet;
    _fitness = copyFrom._fitness;
    copyGenes(copyFrom);
}


DNA_StringSearch& DNA_StringSearch::operator = (const DNA_StringSearch& copyFrom)
{
    _optimalGenes = copyFrom._optimalGenes;
    _geneAlphabet = copyFrom._geneAlphabet;
    _fitness = copyFrom._fitness;
    copyGenes(copyFrom);

    return *this;
}


DNA_StringSearch::~DNA_StringSearch()
{
}


void DNA_StringSearch::initGenesWithRandomValues()
{
    // Creates a string with random characters from the alphabet.

    size_t iAlphabet = 0;

    for (size_t iGene = 0; iGene < _genes.size(); iGene++)
    {
        iAlphabet = getRandomIntegerInRange<size_t>(
            0, _geneAlphabet->size() - 1);

        _genes[iGene] = _geneAlphabet->at(iAlphabet);
    }
}


void DNA_StringSearch::copyGenes(const DNA_StringSearch& copyFrom)
{
    _genes.resize(_optimalGenes->size());

    for (size_t iGene = 0; iGene < copyFrom._genes.size(); iGene++)
        _genes[iGene] = copyFrom._genes[iGene];
}


void DNA_StringSearch::recombineGenes(
    const DNA_StringSearch& parent1,
    const DNA_StringSearch& parent2)
{
    // This DNA will become a child of both parent DNAs by copying some genes
    // of parent1 and some genes of parent2. This recombination is also called
    // crossover. In this demonstration two different crossover methods will be
    // used randomly: crossOver_50_50 and crossOver_withPoint

    if (getRandomTrueWithProbability(0.5))
    {
        crossOver_50_50(parent1, parent2);
    }
    else
    {
        const auto crossOverPointInPercent =
            getRandomRealInRange<double>(0.0, 1.0);

        crossOver_withPoint(parent1, parent2, crossOverPointInPercent);
    }
}


void DNA_StringSearch::mutateGenes(double probability)
{
    // Mutates the string by replacing its characters with a given probability.
    // The characters will be replaced with random characters from
    // the alphabet.

    size_t iAlphabet = 0;

    for (size_t iGene = 0; iGene < _genes.size(); iGene++)
    {
        if (getRandomTrueWithProbability(probability))
        {
            iAlphabet = getRandomIntegerInRange<size_t>(
                0, _geneAlphabet->size() - 1);

            _genes[iGene] = _geneAlphabet->at(iAlphabet);
        }
    }
}


double DNA_StringSearch::calcFitness()
{
    // FITNESS FUNCTION

    // The fitness value of the DNA is defined by the number of wrong
    // characters in the string. In this case the objective is to minimize
    // the fitness value.

    _fitness = 0.0;

    for (size_t iGene = 0; iGene < _genes.size(); iGene++)
        if (_genes[iGene] != _optimalGenes->at(iGene))
            _fitness += 1.0;

    // To get a better separation of different DNAs with a similar fitness,
    // the values can be squared to get exponential instead of linear results
    // (_fitness = _fitness * _fitness). Squared fitness values are not
    // beneficial in this case because the GeneticAlgorithm class uses a
    // rank based selection method for DNAs which sorts all fitness values.

    return _fitness;
}


double DNA_StringSearch::getFitness() const
{
    return _fitness;
}


string DNA_StringSearch::toString() const
{
    string dnaStr = "";

    for (auto& gene : _genes)
        dnaStr += gene;

    return dnaStr;
}


bool DNA_StringSearch::isSolved() const
{
    return (_fitness < 1.0);
}


inline void DNA_StringSearch::crossOver_50_50(
    const DNA_StringSearch& parent1,
    const DNA_StringSearch& parent2)
{
    // This crossover method will copy the genes of two parent DNAs.
    // Every gene in the current DNA has a 50% chance to be copied from dna1
    // and a 50% chance to be copied from dna2.

    for (size_t iGene = 0; iGene < _genes.size(); iGene++)
        if (getRandomTrueWithProbability(0.5))
            _genes[iGene] = parent1._genes[iGene];
        else
            _genes[iGene] = parent2._genes[iGene];
}


inline void DNA_StringSearch::crossOver_withPoint(
    const DNA_StringSearch& parent1,
    const DNA_StringSearch& parent2,
    double crossOverPoint)
{
    // This crossover method will copy the genes of two parent DNAs.
    // All genes before the crossover point (index) will be copied from dna1
    // and all genes after the crossover point will be copied from dna2.
    // Alternative crossover methods may use multiple crossover points to
    // copy different sections from parent DNAs.

    const size_t crossOverIdx =
        static_cast<size_t>(_genes.size() * crossOverPoint);

    for (size_t iGene = 0; iGene < _genes.size(); iGene++)
        if (iGene <= crossOverIdx)
            _genes[iGene] = parent1._genes[iGene];
        else
            _genes[iGene] = parent2._genes[iGene];
}
