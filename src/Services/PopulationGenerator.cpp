#include "PopulationGenerator.h"
#include <cmath>
#include <iostream>

template<typename C, typename F>
void
PopulationGenerator<C, F>::GenerateInitialPopulation(IPopulation<C, F> &population, int populationSize) {
    population.clear();

    for (int i = 0; i < populationSize; ++i) {
        population.add(_randomiser.getValue());
    }
}

template<typename C, typename F>
void PopulationGenerator<C, F>::GenerateNextPopulation(IPopulation<C, F> &population, int populationSize) {
    // TODO: move into one selection class?
    _parentSelection.InitialiseFromPopulation(population);
    _survivorSelection.InitialiseFromPopulation(population);

    population.clear();

    // TODO: CLean population survivor selection
    Probability temp(0.01);
    vector<Chromosome<C, F>> fittestVector = _survivorSelection.GetFittest(temp);
    Chromosome<C, F> fittest = fittestVector[0];

    cout << "Fittest " << fittest.getValue() << " " << fittest.getFitness() << endl;
    cout << endl;

//    population.add(fittest.getFitness());
    // TODO: overload population function to take chromosome, and vector of chromosomes

    auto numberOfRandomGenes = ceil(_percentOfRandomPopulation.getValue() * populationSize);
    // make while loop so that it doesn't overfill population
    for (int i = 0; i < numberOfRandomGenes; ++i) {
        population.add(_randomiser.getValue());
    }

    while (population.size() < populationSize) {
        auto parent1 = _parentSelection.SelectParent();
        auto parent2 = _parentSelection.SelectParent();

        // Parent1 should not be the same as parent2
        while (parent1.getValue() == parent2.getValue()) {
            parent2 = _parentSelection.SelectParent();
        }

        auto child = _breeder.Breed(parent1.getValue(), parent2.getValue());
        child = _mutator.Mutate(child);

        population.add(child);
    }
}
