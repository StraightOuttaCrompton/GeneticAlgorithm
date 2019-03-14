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

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    int initialPopulationSize = 10;
    int generations = 10;


    // Data structures
    Population<string> population;
    MatingPool<string, int> matingPool;
    PopulationSelector<string, int> populationSelector;

    // Customisable components
    StringBreeder breeder;
    StringFitnessFunction fitnessFunction;
    StringRandomiser randomiser;
    StringMutator mutator;



//    Evolution<string, int> ga(initialPopulationSize, generations, breeder, fitnessFunction, randomiser, mutator,
//                              population, populationSelector);

//    ga.Start();

    return 0;
}