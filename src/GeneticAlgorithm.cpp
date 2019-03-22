#include "GeneticAlgorithm.h"
#include <iostream>
#include <cmath>


template<class G, class F>
void GeneticAlgorithm<G, F>::Start() {
    // TODO: implement parent and survivor selections generally, so that the implementations can change
    // https://medium.com/datadriveninvestor/genetic-algorithms-selection-5634cfc45d78
    initialisePopulation();

    for (int j = 0; j < _generations; ++j) {
        cout << "Generation: " << j + 1 << endl;

        _matingPool.InitialiseFromPopulation(_population);
        _matingPool.Print();

        _population.clear();

        auto numberOfRandomGenes = ceil(_percentOfRandomPopulation.getValue() * _populationSize);
        addRandomGenesToPopulation((int) numberOfRandomGenes);

        while (_population.size() < _populationSize) {
            // TODO: Parent selection
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

        // TODO: SurvivorSelection
//        _populationSelector.SelectFittest(_population, _populationSize);
    }

    // TODO: Return fitest item, or return entire list in order of fitness?
}

template<class G, class F>
void GeneticAlgorithm<G, F>::initialisePopulation() {
    for (int i = 0; i < _populationSize; ++i) {
        addToPopulation(_geneRandomiser.getValue());
    }
}

template<class G, class F>
void GeneticAlgorithm<G, F>::generateNextGeneration() {
}

template<class G, class F>
void GeneticAlgorithm<G, F>::addToPopulation(G geneValue) {
    auto fitness = _fitnessFunction.Fitness(geneValue);

    Gene<G, F> gene(geneValue, fitness);

    _population.add(gene);
}

template<class G, class F>
void GeneticAlgorithm<G, F>::addRandomGenesToPopulation(int numberOfRandomGenes) {
    for (int i = 0; i < numberOfRandomGenes; ++i) {
        addToPopulation(_geneRandomiser.getValue());
    }
}

