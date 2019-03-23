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

#include "RouletteWheel/RouletteWheelSelection.h"
#include "RouletteWheel/RouletteWheelSelection.cpp" // Avoid linking error

#include <memory>

using namespace std;

int main() {
    // Todo:
    // 1. rename gene to chromosome
    // 2. consider termination condition
    // 3. fix mating pool print? Something was wrong
    // 4. Create IGeneticAlgorithmInterface

    // n. Go through TODOs

    const int populationSize = 4;
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

    // TODO: change how parent seletion works
    RouletteWheelSelection<string, int> rouletteWheelSelection;
    MatingPool<string, int> matingPool(rouletteWheelSelection);

    PopulationGenerator<string, int> populationGenerator(percentOfRandomPopulation, matingPool, scRandomiser, scBreeder,
                                                         scMutator);


    GeneticAlgorithm<string, int> geneticAlgorithm(populationSize, generations, population, populationGenerator);

    geneticAlgorithm.Start();

    Chromosome<string, int> fittest = geneticAlgorithm.GetFittest();

    cout << fittest.getValue() << endl;
    cout << fittest.getFitness() << endl;


    return 0;
}