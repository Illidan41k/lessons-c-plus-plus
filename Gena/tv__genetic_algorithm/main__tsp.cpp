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
#include "dna_tsp.hpp"


int main()
{
    // The Genetic Algorithm will be initialized with a Travelling Salesman
    // Problem. The total length of a route through many locations should
    // be minimized.

    // The 'Berlin52' data set consists of 52 route locations.

    const vector<double> routeLocationsX =
        { 565.0, 25.0, 345.0, 945.0, 845.0, 880.0, 25.0, 525.0, 580.0, 650.0,
          1605.0, 1220.0, 1465.0, 1530.0, 845.0, 725.0, 145.0, 415.0, 510.0, 560.0,
          300.0, 520.0, 480.0, 835.0, 975.0, 1215.0, 1320.0, 1250.0, 660.0, 410.0,
          420.0, 575.0, 1150.0, 700.0, 685.0, 685.0, 770.0, 795.0, 720.0, 760.0,
          475.0, 95.0, 875.0, 700.0, 555.0, 830.0, 1170.0, 830.0, 605.0, 595.0,
          1340.0, 1740.0 };

    const vector<double> routeLocationsY =
        { 575.0, 185.0, 750.0, 685.0, 655.0, 660.0, 230.0, 1000.0, 1175.0, 1130.0,
          620.0, 580.0, 200.0, 5.0, 680.0, 370.0, 665.0, 635.0, 875.0, 365.0,
          465.0, 585.0, 415.0, 625.0, 580.0, 245.0, 315.0, 400.0, 180.0, 250.0,
          555.0, 665.0, 1160.0, 580.0, 595.0, 610.0, 610.0, 645.0, 635.0, 650.0,
          960.0, 260.0, 920.0, 500.0, 815.0, 485.0, 65.0, 610.0, 625.0, 360.0,
          725.0, 245.0 };

    //  The correct answer for the 'Berlin52' data set is known, so this specific
    //  Travelling Salesman Problem can be used to evaluate the performance of
    //  the Genetic Algorithm. The shortest route (global optimal solution) is:
    //
    //  { 0, 48, 31, 44, 18, 40, 7, 8, 9, 42, 32, 50, 10, 51, 13, 12, 46, 25, 26,
    //   27, 11, 24, 3, 5, 14, 4, 23, 47, 37, 36, 39, 38, 35, 34, 33, 43, 45, 15,
    //   28, 49, 19, 22, 29, 1, 6, 41, 20, 16, 2, 17, 30, 21, (0) } Length: 7544.366
    //
    //  The route is a loop of location indices and can be read in
    //  forward or backward direction.

    const double optimalRouteLength = 7544.366; 

    auto initialDNA = DNA_TSP(routeLocationsX, routeLocationsY, optimalRouteLength);
    initialDNA.initGenesWithRandomValues();

    const size_t populationSize = 12;
    const double percentOfBestCanReproduce = 50.0;
    const double recombinationProbability = 0.9;   
    const double mutationProbability = 0.3;

    auto ga = unique_ptr< GeneticAlgorithm<DNA_TSP> >(
        new GeneticAlgorithm<DNA_TSP> (
            &initialDNA,
            GeneticAlgorithmObjective::Minimization,
            populationSize,
            percentOfBestCanReproduce,
            recombinationProbability,
            mutationProbability) );

    cout << "\nOPTIMIZATION STARTED ...\n\n";

    cout << "Population size: " << ga->getPopulationSize() << "\n";
    cout << "Percent Of best DNA can reproduce: " << percentOfBestCanReproduce << "%\n";
    cout << "Recombination probability: " << recombinationProbability * 100.0 << "%\n";
    cout << "Mutation probability: " << mutationProbability * 100.0 << "%\n\n";

    auto printGeneration = [&]()
    {
        cout << "Generation: "
             << left << setw(5) << ga->getNumEvolvedGenerations()
             << "   Best Fitness: "
             << left << setw(10) << fixed
             << setprecision(4)  << ga->getBestDNAfitness() << "\n";
    };

    printGeneration();

    while (!ga->isProblemSolved())
    {
        ga->evolveNextGeneration();
        printGeneration();
    }

    if (ga->isProblemSolved())
    {
        cout << "\nSOLVED!\n\n";
        cout << "Number of evolved generations: "  << ga->getNumEvolvedGenerations() << "\n";
        cout << "Number of improved generations: " << ga->getNumGenerationImprovements() << "\n";
        cout << "Number of fitness evaluations: "  << ga->getNumFitnessEvaluations() << "\n";
        cout << "Number of fitness improvements: " << ga->getNumFitnessImprovements() << "\n";

        if (ga->getNumEvolvedGenerations())
        {
            const auto fitnessImprovementsPerGeneration =
                    static_cast<double>(ga->getNumFitnessImprovements()) /
                    static_cast<double>(ga->getNumEvolvedGenerations());

            cout << "Number of fitness improvements per generation: "
                 << fitnessImprovementsPerGeneration << "\n\n\n";
        }
    }

    system("pause");
    return 0;
}
