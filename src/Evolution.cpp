#include <iostream>
#include "Evolution.h"

template<class G, class F>
void Evolution<G, F>::Start() {
    // initialise population
    for (int i = 0; i < _initialPopulationSize; ++i) {
        _population.add(_geneRandomiser.getRandomGene());
    }


    for (int j = 0; j < _generations; ++j) {
        // Selection
        _populationSelector.PopulateMatingPool(_population, _fitnessFunction, _matingPool);

        vector<G> nextPopulation;

        for (int i = 0; i < _initialPopulationSize; ++i) {
            // GetEligibleParents - return vector of parents. I don't want parent1 and parent2 to be the same?
            G parent1 = _matingPool.getEligibleParent();
            G parent2 = _matingPool.getEligibleParent();

            G child = _breeder.Breed(parent1, parent2);

            child = _mutator.Mutate(child);

            nextPopulation.push_back(child);
        }

        _population.replace(nextPopulation);
    }

    // TODO: Return fitest item, or return entire list in order of fitness?
}
