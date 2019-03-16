#include <iostream>
#include "Evolution.h"

template<class G, class F>
void Evolution<G, F>::Start() {
    // initialise population
    for (int i = 0; i < _initialPopulationSize; ++i) {
        _population.add(_geneRandomiser.getRandomGene());
    }

    for (int j = 0; j < _generations; ++j) {
        cout << "Generation: " << j + 1 << endl;
        // Selection
        _populationSelector.PopulateMatingPool(_population, _fitnessFunction, _matingPool);

        _matingPool.print();

        vector<G> nextPopulation;

        nextPopulation.push_back(_geneRandomiser.getRandomGene());

        while (nextPopulation.size() < _initialPopulationSize) {
            auto parent1 = _matingPool.getEligibleParent();
            auto parent2 = _matingPool.getEligibleParent();

            // Parent1 should not be the same as parent2
//            while(parent1 == parent2) {
//                parent2 = _matingPool.getEligibleParent();
//            }

            auto child = _breeder.Breed(parent1, parent2);
            child = _mutator.Mutate(child);

            nextPopulation.push_back(child);
        }


        // TODO: keep fittest?
        _population.replace(nextPopulation);
    }

    // TODO: Return fitest item, or return entire list in order of fitness?
}
