
// Copyright by Tim Völcker - All rights reserved.
// See the complete tutorial at www.timvoelcker.de/genetic_algorithm.html


// The algorithm is composed of two classes. A reusable GeneticAlgorithm
// class and a DNA class which implements a specific problem:
//
// -  The GeneticAlgorithm class guides the evolution process of DNAs.
//    It manages the DNAs of the current population and next generation
//    and implements a strategy to select parent DNAs for reproduction.
//    It can be used for different problems without modification.
//
// -  A DNA class implements a particular problem to be solved by a
//    Genetic Algorithm. The class manages its own reproduction with
//    recombination / crossover, its mutation and fitness evaluation.
//    A DNA class is not very reusable and must be customized for each
//    problem.
//
// There is no abstract base class for a DNA to inherit from. A user has to
// implement a DNA class with its particular methods and inject it into a
// GeneticAlgorithm by using templates. With this 'duck typing' approach all
// types will be figured out at compile time and not at runtime.


#include <memory>
using std::unique_ptr;

#include <iostream>
using std::cout;

#include <iomanip>
using std::left;
using std::setw;
using std::fixed;
using std::setprecision;

#include "genetic_agorithm.hpp"
#include "dna_string_search.hpp"


//int main()
//{
//    // The Genetic Algorithm will be initialized with a string search
//    // problem. The number of wrong characters in a random string
//    // should be minimized until the correct string is found. 
//
//    // A DNA (string) should be evolved which matches the following
//    // genes (characters):
//
//    const string findThisString =
//    "If I have seen further it is by standing on the shoulders of giants.";
//
//    // On initialization or mutation of the DNA its genes
//    // can be selected from the following alphabet:
//
//    const string alphabet =
//        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .";
//
//    auto initialDNA = DNA_StringSearch(findThisString, alphabet);
//    initialDNA.initGenesWithRandomValues();
//
//    const size_t populationSize = 50000;
//    const double percentOfBestCanReproduce = 2.5;
//    const double recombinationProbability = 0.9;  // 90%
//    const double mutationProbability = 0.01;      //  1%
//
//    auto ga = unique_ptr< GeneticAlgorithm<DNA_StringSearch> >(
//        new GeneticAlgorithm<DNA_StringSearch>(
//            &initialDNA,
//            GeneticAlgorithmObjective::Minimization,
//            populationSize,
//            percentOfBestCanReproduce,
//            recombinationProbability,
//            mutationProbability) );
//
//    cout << "\nOPTIMIZATION STARTED ...\n\n";
//
//    cout << "Population size: " << ga->getPopulationSize() << "\n";
//    cout << "Percent Of best DNA can reproduce: " << percentOfBestCanReproduce << "%\n";
//    cout << "Recombination probability: " << recombinationProbability * 100.0 << "%\n";
//    cout << "Mutation probability: " << mutationProbability * 100.0 << "%\n\n";
//
//    auto printGeneration = [&]()
//    {
//        cout << "Generation: "
//             << left << setw(5) << ga->getNumEvolvedGenerations()
//             << "   Best Fitness: "
//             << left << setw(10) << fixed
//             << setprecision(4)  << ga->getBestDNAfitness() << "\n";
//    };
//
//    printGeneration();
//
//    while (!ga->isProblemSolved())
//    {
//        ga->evolveNextGeneration();
//        printGeneration();
//    }
//
//    if (ga->isProblemSolved())
//    {
//        cout << "\nSOLVED!\n\n";
//        cout << "Number of evolved generations: "  << ga->getNumEvolvedGenerations() << "\n";
//        cout << "Number of improved generations: " << ga->getNumGenerationImprovements() << "\n";
//        cout << "Number of fitness evaluations: "  << ga->getNumFitnessEvaluations() << "\n";
//        cout << "Number of fitness improvements: " << ga->getNumFitnessImprovements() << "\n";
//
//        if (ga->getNumEvolvedGenerations())
//        {
//            const auto fitnessImprovementsPerGeneration =
//                    static_cast<double>(ga->getNumFitnessImprovements()) /
//                    static_cast<double>(ga->getNumEvolvedGenerations());
//
//            cout << "Number of fitness improvements per generation: "
//                 << fitnessImprovementsPerGeneration << "\n\n\n";
//        }
//    }
//
//    return 0;
//}
