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

using namespace std;

int main() {
    // Todo:
    // 1. Add unit tests?
    // 2. consider termination condition

    // n. Go through TODOs


    // Genetic algorithm parameters
    const int populationSize = 260;
    const int generations = 50;
    Probability percentOfRandomPopulation(0.05);
    Probability percentOfFittestPopulation(0.1);
    Probability mutationRate(0.05);

    // Substitution cipher
    string charPool = "abcdefghijklmnopqrstuvwxyz";
    SCBreeder scBreeder(charPool);
    SCFitnessFunction scFitnessFunction(charPool);
    SCRandomiser scRandomiser(charPool);
    SCMutator scMutator(mutationRate);

    // Selection
    RouletteWheelSelector<string, int> parentSelector;
    FittestSelector<string, int> survivorSelector;
    PopulationSelector<string, int> populationSelector(parentSelector, survivorSelector);


    PopulationGenerator<string, int> populationGenerator(percentOfRandomPopulation, percentOfFittestPopulation,
                                                         populationSelector, scRandomiser, scBreeder, scMutator);

    Population<string, int> population(scFitnessFunction);

    GeneticAlgorithm<string, int> geneticAlgorithm(populationSize, generations, population, populationGenerator);

    geneticAlgorithm.Start();


//    Chromosome<string, int> fittest = geneticAlgorithm.GetFittest();
//
//    cout << fittest.GetValue() << endl;
//    cout << fittest.GetFitness() << endl;

    return 0;
}
