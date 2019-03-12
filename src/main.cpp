#include <iostream>
#include "Population.h"
#include "stringGa/StringBreeder.h"
#include "stringGa/StringFitnessFunction.h"
#include "stringGa/StringRandomiser.h"
#include "stringGa/StringMutator.h"
#include "PopulationSelector.h"
#include "Evolution.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    int initialPopulationSize = 10;
    int generations = 10;

    // data structures
    Population<string> *population;
    PopulationSelector<string, int> populationSelector;

    // Customisable components
    StringBreeder breeder;
    StringFitnessFunction fitnessFunction;
    StringRandomiser randomiser;
    StringMutator *mutator;

    Evolution<string, int> ga(initialPopulationSize, generations, breeder, fitnessFunction, randomiser, mutator,
                              population, populationSelector);

//    ga.Start();

    return 0;
}