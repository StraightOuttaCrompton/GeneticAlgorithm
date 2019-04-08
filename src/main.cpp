#include "Constructs/Population.h"
#include "Constructs/Population.cpp" // Avoid linking error
#include "Constructs/PopulationGenerator.h"
#include "Constructs/PopulationGenerator.cpp" // Avoid linking error
#include "Constructs/PopulationSelector.h"
#include "Constructs/PopulationSelector.cpp" // Avoid linking error

#include "Implementations/SubstitutionCipher/SCBreeder.h"
#include "Implementations/SubstitutionCipher/SCFitnessFunction.h"
#include "Implementations/SubstitutionCipher/SCRandomiser.h"
#include "Implementations/SubstitutionCipher/SCMutator.h"

#include "GeneticAlgorithm.h"
#include "GeneticAlgorithm.cpp" // Avoid linking error

#include "Models/Probability.h"

#include "Selectors/RouletteWheelSelector.h"
#include "Selectors/RouletteWheelSelector.cpp" // Avoid linking error
#include "Selectors/FittestSelector.h"
#include "Selectors/FittestSelector.cpp" // Avoid linking error

#include <memory>

using namespace std;

int main() {
    // Todo:
    // 1. rename gene to chromosome
    // 2. consider termination condition
    // 3. fix mating pool print? Something was wrong
    // 4. Create IGeneticAlgorithmInterface
    // Survivor selection and Parent selection repeat code
    // Implement FittestSelector
    // Add unit tests?
    // Capitalise public functions

    // n. Go through TODOs

    const int populationSize = 4;
    const int generations = 10;
    Probability percentOfRandomPopulation(0.1);
    Probability percentOfFittestPopulation(0.2);
    Probability mutationRate(0.05);

    // Substitution cipher
    // TODO: create key class abstraction
//    string charPool = "abcdefghijklmnopqrstuvwxyz";
    string charPool = "abcd";
    SCBreeder scBreeder(charPool);
    SCFitnessFunction scFitnessFunction(charPool);
    SCRandomiser scRandomiser(charPool);
    SCMutator scMutator(mutationRate);

    // Constructs - rename to constructs?
    // TODO: Should the population take the fitness function in it's constructor?
    Population<string, int> population(scFitnessFunction);

    RouletteWheelSelector<string, int> parentSelector;
    FittestSelector<string, int> survivorSelector;
    PopulationSelector<string, int> populationSelector(parentSelector, survivorSelector);


    PopulationGenerator<string, int> populationGenerator(percentOfRandomPopulation, percentOfFittestPopulation,
                                                         populationSelector, scRandomiser, scBreeder, scMutator);

    GeneticAlgorithm<string, int> geneticAlgorithm(populationSize, generations, population, populationGenerator);

    geneticAlgorithm.Start();


    Chromosome<string, int> fittest = geneticAlgorithm.GetFittest();

    cout << fittest.getValue() << endl;
    cout << fittest.getFitness() << endl;

    return 0;
}