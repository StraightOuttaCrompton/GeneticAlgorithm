#include <iostream>
#include "Evolution.h"

template<class G, class F>
void Evolution<G, F>::Start() {
    cout << "Start" << endl;
//    // initialise population
//    for (int i = 0; i < _initialPopulationSize; ++i) {
//        _population.add(_geneRandomiser.getRandomGene());
//    }
//
//    for (int j = 0; j < _generations; ++j) {
//        // Selection
//        IMatingPool<G, F> matingPool = _populationSelector.CreateMatingPool(_population, _fitnessFunction);
//
//        vector<G> nextPopulation;
//        for (int i = 0; i < _initialPopulationSize; ++i) {
//            G parent1 = matingPool.getEligibleParent();
//            G parent2 = matingPool.getEligibleParent();
//
//            G child = _breeder.Breed(parent1, parent2);
//
//            child = _mutator.Mutate(child, mutationRate);
//
//            nextPopulation.push_back(child);
//        }
//
//        _population.replace(nextPopulation);
//    }
}
