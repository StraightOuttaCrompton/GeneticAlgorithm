#include "Services/Population.h"
#include "Services/Population.cpp" // Avoid linking error
#include "Services/PopulationGenerator.h"
#include "Services/PopulationGenerator.cpp" // Avoid linking error

#include "Implementations/SubstitutionCipher/SCBreeder.h"
#include "Implementations/SubstitutionCipher/SCFitnessFunction.h"
#include "Implementations/SubstitutionCipher/SCRandomiser.h"
#include "Implementations/SubstitutionCipher/SCMutator.h"

#include "GeneticAlgorithm.h"
#include "GeneticAlgorithm.cpp" // Avoid linking error

#include "Models/Probability.h"

#include "Selection/RouletteWheelParentSelection.h"
#include "Selection/RouletteWheelParentSelection.cpp" // Avoid linking error
#include "Selection/FittestSurvivorSelection.h"
#include "Selection/FittestSurvivorSelection.cpp" // Avoid linking error

#include <memory>

using namespace std;

int main() {
    // Todo:
    // 1. rename gene to chromosome
    // 2. consider termination condition
    // 3. fix mating pool print? Something was wrong
    // 4. Create IGeneticAlgorithmInterface
    // Survivor selection and Parent selection repeat code
    // Implement FittestSurvivorSelection

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
//    auto population = std::make_shared<PfittestSurvivorSelectionopulation<string, int>>(scFitnessFunction);
    Population<string, int> population(scFitnessFunction);

    // TODO: change how parent seletion works
    RouletteWheelParentSelection<string, int> rouletteWheelParentSelection;
    FittestSurvivorSelection<string, int> fittestSurvivorSelection;


    // TODO: pass in percentOfFittestPopulation
    //  check that percentOfRandomPopulation and percentOfFittestPopulation aren't more than 1 - maybe do this in Probability class
    PopulationGenerator<string, int> populationGenerator(percentOfRandomPopulation, rouletteWheelParentSelection,
                                                         fittestSurvivorSelection, scRandomiser, scBreeder, scMutator);


    GeneticAlgorithm<string, int> geneticAlgorithm(populationSize, generations, population, populationGenerator);

    geneticAlgorithm.Start();

    Chromosome<string, int> fittest = geneticAlgorithm.GetFittest();

    cout << fittest.getValue() << endl;
    cout << fittest.getFitness() << endl;


    return 0;
}