
// Copyright (C) by Tim Völcker. All rights reserved.
// See the complete tutorial at www.timvoelcker.de/genetic_algorithm.html

// A DNA class implements a particular problem to be solved by a Genetic
// Algorithm. The class manages its own reproduction, mutation and fitness
// evaluation. There is no abstract base class for a DNA to inherit from.
// A user has to implement the class with its particular methods and inject
// it into a Genetic Algorithm by using templates. With this 'duck typing'
// approach there will be no performance overhead by runtime method binding
// (virtual functions). All types will be figured out at compile time.

// This DNA class implements a solution for a string search problem.
// The problem and solution has no application in real life but it will be used
// to demonstrate the performance and possibilities of a Genetic Algorithm.
// A given string should be found from all possible strings. The genes of the
// DNA are the string characters which will be selected from a given alphabet.
// The fitness value of the DNA is defined by the number of wrong characters
// in the string. In this case the objective is to minimize the fitness value.


#pragma once

#include <algorithm>
#include <numeric>

#include <array>
using std::array;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "randnumgen.hpp"


class DNA_StringSearch
{
// Methods to be called by the GeneticAlgorithm class:
public:

    DNA_StringSearch(const string& findThisString, const string& alphabet);
    DNA_StringSearch(const DNA_StringSearch& copyFrom);
    DNA_StringSearch& operator = (const DNA_StringSearch& copyFrom);
   ~DNA_StringSearch();

public:

    void initGenesWithRandomValues();
    void copyGenes(const DNA_StringSearch& copyFrom);
    void recombineGenes(const DNA_StringSearch& parent1, const DNA_StringSearch& parent2);
    void mutateGenes(double probability);

    double calcFitness();
    double getFitness() const;

    string toString() const;

    bool isSolved() const;
    

// Specific methods and properties for a string search problem:
private:

    inline void crossOver_50_50(
        const DNA_StringSearch& parent1,
        const DNA_StringSearch& parent2);

    inline void crossOver_withPoint(
        const DNA_StringSearch& parent1,
        const DNA_StringSearch& parent2,
        double crossOverPoint);

private:
    const string* _geneAlphabet;
    const string* _optimalGenes;
    vector<char> _genes;
    double _fitness;
};
