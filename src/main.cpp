#include "Services/Population.h"
#include "Services/Population.cpp" // Avoid linking error
#include "Services/MatingPool.h"
#include "Services/MatingPool.cpp" // Avoid linking error
#include "Services/PopulationSelector.h"
#include "Services/PopulationSelector.cpp" // Avoid linking error

#include "Implementations/SubstitutionCipher/SCBreeder.h"
#include "Implementations/SubstitutionCipher/SCFitnessFunction.h"
#include "Implementations/SubstitutionCipher/SCRandomiser.h"
#include "Implementations/SubstitutionCipher/SCMutator.h"

#include "GeneticAlgorithm.h"
#include "GeneticAlgorithm.cpp" // Avoid linking error

#include "Models/Probability.h"

using namespace std;

int main() {
    // Todo:
    // 1. remove roulette wheel item, use std:: pair

    const int populationSize = 10;
    const int generations = 4;
    Probability percentOfRandomPopulation(0.1);
    Probability mutationRate(0.05);


//    const int populationSize = 100;
//    const int generations = 40;
//    Probability mutationRate(0.05);

    // Services
    Population<string, int> population;
    PopulationSelector<string, int> populationSelector;
    MatingPool<string, int> matingPool;

    // Substitution cipher
    // TODO: create key class abstraction
    string charPool = "abcdefghijklmnopqrstuvwxyz";
    SCBreeder scBreeder(charPool);
    SCFitnessFunction scFitnessFunction(charPool);
    SCRandomiser scRandomiser(charPool);
    SCMutator scMutator(mutationRate);

    GeneticAlgorithm<string, int> geneticAlgorithm(populationSize, generations, percentOfRandomPopulation, population, populationSelector,
                                                   matingPool, scFitnessFunction, scRandomiser, scBreeder, scMutator);

    geneticAlgorithm.Start();

    return 0;
}