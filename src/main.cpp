#include <iostream>

#include "Population.h"
#include "Population.cpp" // Avoid linking error
#include "MatingPool.h"
#include "MatingPool.cpp" // Avoid linking error
#include "PopulationSelector.h"
#include "PopulationSelector.cpp" // Avoid linking error

#include "stringGa/StringBreeder.h"
#include "stringGa/StringFitnessFunction.h"
#include "stringGa/StringRandomiser.h"
#include "stringGa/StringMutator.h"

#include "Evolution.h"
#include "Evolution.cpp" // Avoid linking error

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    int initialPopulationSize = 10;
    int generations = 10;
    int mutationRate = 100; // not doing anything yet


    // Data structures
    Population<string> population;
    PopulationSelector<string, int> populationSelector;
    MatingPool<string, int> matingPool;

    // Customisable components
    StringBreeder breeder;
    StringFitnessFunction fitnessFunction;
    StringRandomiser randomiser;
    StringMutator mutator;


    Evolution<string, int> ga(initialPopulationSize, generations, mutationRate, population, populationSelector,
                              matingPool,
                              fitnessFunction, randomiser, breeder,
                              mutator);

    ga.Start();

    return 0;
}