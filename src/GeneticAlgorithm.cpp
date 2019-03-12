#include "GeneticAlgorithm.h"

template<class G, class F>
void GeneticAlgorithm<G, F>::Start() {
    int mutationRate = 1000;

    // initialise population
    for (int i = 0; i < _initialPopulationSize; ++i) {
        _population.add(_geneRandomiser.getRandomGene());
    }


    for (int j = 0; j < _generations; ++j) {
        // Selection
        IMatingPool<G> matingPool = _populationSelector.getMatingPool(_population, _fitnessFunction);


        deque<G> nextPopulation;
        for (int i = 0; i < _initialPopulationSize; ++i) {
            G parent1 = matingPool.getEligibleParent();
            G parent2 = matingPool.getEligibleParent();

            G child = _breeder.Breed(parent1, parent2);

            child = _mutator.Mutate(child, mutationRate);

            nextPopulation.push_back(child);
        }

        _population.replace(nextPopulation);
    }
}
