#include "GeneticAlgorithm.h"
#include <iostream>

template<class G, class F>
void GeneticAlgorithm<G, F>::addToPopulation(G geneValue) {
    auto fitness = _fitnessFunction.Fitness(geneValue);

    Gene<G, F> gene(geneValue, fitness);

    _population.add(gene);
}

template<class G, class F>
void GeneticAlgorithm<G, F>::Start() {
    // Initialise population
    for (int i = 0; i < _initialPopulationSize; ++i) {
        addToPopulation(_geneRandomiser.getValue());
    }

    for (int j = 0; j < _generations; ++j) {
        cout << "Generation: " << j + 1 << endl;

        _matingPool.InitialiseFromPopulation(_population);
        _matingPool.Print();

        // Todo: have a percentage of the population be random?
        addToPopulation(_geneRandomiser.getValue());

        for (int k = 0; k < _initialPopulationSize - 1; ++k) {
            auto parent1 = _matingPool.GetEligibleParent();
            auto parent2 = _matingPool.GetEligibleParent();

            // Parent1 should not be the same as parent2
            while (parent1 == parent2) {
                parent2 = _matingPool.GetEligibleParent();
            }

            auto child = _breeder.Breed(parent1, parent2);
            child = _mutator.Mutate(child);

            addToPopulation(child);
        }

        _populationSelector.NaturalSelection(_population, _fitnessFunction,
                                             _initialPopulationSize);
    }

    // TODO: Return fitest item, or return entire list in order of fitness?
}
