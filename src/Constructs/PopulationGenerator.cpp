#include "PopulationGenerator.h"
#include <cmath>
#include <iostream>

template<typename C, typename F>
void PopulationGenerator<C, F>::GenerateInitialPopulation(IPopulation<C, F> &population, int populationSize) {
    population.clear();

    for (int i = 0; i < populationSize; ++i) {
        population.add(_randomiser.getValue());
    }
}

template<typename C, typename F>
void PopulationGenerator<C, F>::GenerateNextPopulation(IPopulation<C, F> &population, int populationSize) {
    _populationSelector.InitialiseFromPopulation(population);

    population.clear();

    // Add survivors
    vector<Chromosome<C, F>> survivors = _populationSelector.SelectSurvivors(_percentOfFittestPopulation);
    population.add(survivors);

    // Add random genes
    auto numberOfRandomGenes = ceil(_percentOfRandomPopulation.getValue() * populationSize);

    // TODO: make while loop so that it doesn't overfill population
    for (int i = 0; i < numberOfRandomGenes; ++i) {
        population.add(_randomiser.getValue());
    }

    // Add fill rest of population with children bred from breeding pool
    while (population.size() < populationSize) {
        auto parent1 = _populationSelector.SelectParent();
        auto parent2 = _populationSelector.SelectParent();

        // Parent1 should not be the same as parent2
        while (parent1.getValue() == parent2.getValue()) {
            parent2 = _populationSelector.SelectParent();
        }

        C child = _breeder.Breed(parent1.getValue(), parent2.getValue());
        child = _mutator.Mutate(child);

        population.add(child);
    }
}
