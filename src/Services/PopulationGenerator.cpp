#include "PopulationGenerator.h"
#include <cmath>

//
//template<typename C, typename F>
//void PopulationGenerator<C, F>::SelectFittest(IPopulation<C, F> &population,
//                                             int populationSize) {
//    _addedGenes = {};
//    _pq = {};
//
//    vector<Chromosome<C, F>> populationVector = population.getPopulationVector();
//
//    for (int i = 0; i < populationVector.size(); ++i) {
//        Chromosome<C, F> gene = populationVector[i];
//
//        const bool is_in = _addedGenes.find(gene.getValue()) != _addedGenes.end();
//
//        if (!is_in) {
//            _pq.push(gene);
//            _addedGenes.insert(gene.getValue());
//        }
//    }
//
//    vector<Chromosome<C, F>> nextPopulation;
//    while (nextPopulation.size() < populationSize && !_pq.empty()) {
//        Chromosome<C, F> topGene = _pq.top();
//        nextPopulation.push_back(topGene);
//        _pq.pop();
//    }
//
//    population.Replace(nextPopulation);

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
    _parentSelection.InitialiseFromPopulation(population);

    Chromosome<C, F> fittest = population.Fittest();

    population.clear();

    // do population survivor selection
    population.add(fittest.getValue()); // TODO: overload population function to take chromosome

    auto numberOfRandomGenes = ceil(_percentOfRandomPopulation.getValue() * populationSize);
    // make while loop so that it doesn't overfill population
    for (int i = 0; i < numberOfRandomGenes; ++i) {
        population.add(_randomiser.getValue());
    }

    while (population.size() < populationSize) {
        // TODO: Parent selection
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
