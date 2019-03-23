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

template<typename G, typename F>
void
PopulationGenerator<G, F>::GenerateInitialPopulation(shared_ptr<IPopulation<G, F>> population, int populationSize) {
    population->clear();

    for (int i = 0; i < populationSize; ++i) {
        population->add(_randomiser.getValue());
    }
}

template<typename G, typename F>
void PopulationGenerator<G, F>::GenerateNextPopulation(shared_ptr<IPopulation<G, F>> population, int populationSize) {
    _matingPool.InitialiseFromPopulation(population);
    _matingPool.Print();

    population->clear();

    auto numberOfRandomGenes = ceil(_percentOfRandomPopulation.getValue() * populationSize);
    for (int i = 0; i < numberOfRandomGenes; ++i) {
        population->add(_randomiser.getValue());
    }

    while (population->size() < populationSize) {
        // TODO: Parent selection
        auto parent1 = _matingPool.GetEligibleParent();
        auto parent2 = _matingPool.GetEligibleParent();

        // Parent1 should not be the same as parent2
        while (parent1 == parent2) {
            parent2 = _matingPool.GetEligibleParent();
        }

        auto child = _breeder.Breed(parent1, parent2);
        child = _mutator.Mutate(child);

        population->add(child);
    }
}
