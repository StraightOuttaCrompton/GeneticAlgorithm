#include "Services/Population.h"
#include "Services/Population.cpp" // Avoid linking error
#include "Services/MatingPool.h"
#include "Services/MatingPool.cpp" // Avoid linking error
#include "Services/PopulationGenerator.h"
#include "Services/PopulationGenerator.cpp" // Avoid linking error

#include "Implementations/SubstitutionCipher/SCBreeder.h"
#include "Implementations/SubstitutionCipher/SCFitnessFunction.h"
#include "Implementations/SubstitutionCipher/SCRandomiser.h"
#include "Implementations/SubstitutionCipher/SCMutator.h"

#include "GeneticAlgorithm.h"
#include "GeneticAlgorithm.cpp" // Avoid linking error

#include "Models/Probability.h"

#include <memory>

using namespace std;

int main() {
    // Todo:
    // 1. remove roulette wheel item, use std:: pair
    // 2. rename gene to chromosome
    // 3. consider termination condition

    // n. Go through TODOs

    const int populationSize = 10;
    const int generations = 10;
    Probability percentOfRandomPopulation(0.1);
    Probability mutationRate(0.05);


//    const int populationSize = 100;
//    const int generations = 40;
//    Probability mutationRate(0.05);


    // Substitution cipher
    // TODO: create key class abstraction
    string charPool = "abcdefghijklmnopqrstuvwxyz";
    SCBreeder scBreeder(charPool);
    SCFitnessFunction scFitnessFunction(charPool);
    SCRandomiser scRandomiser(charPool);
    SCMutator scMutator(mutationRate);

    // Services - rename to constructs?

    // TODO: Should the population take the fitness function in it's constructor?
    auto population = std::make_shared<Population<string, int>>(scFitnessFunction);

    MatingPool<string, int> matingPool; // TODO: think about parent selection flexibility, use other selections other than rouletteWheel

    PopulationGenerator<string, int> populationGenerator(percentOfRandomPopulation, matingPool, scRandomiser, scBreeder,
                                                         scMutator);


    GeneticAlgorithm<string, int> geneticAlgorithm(populationSize, generations, population, populationGenerator);

    Chromosome<string, int> fittest = geneticAlgorithm.Start();

    cout << fittest.getValue() << endl;
    cout << fittest.getFitness() << endl;


    return 0;
}