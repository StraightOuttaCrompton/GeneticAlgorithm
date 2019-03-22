#include <iostream>
#include "PopulationGenerator.h"


//template<class G, class F>
//void GeneticAlgorithm<G, F>::initialisePopulation() {
//    for (int i = 0; i < _populationSize; ++i) {
//        addToPopulation(_geneRandomiser.getValue());
//    }
//}

//template<class G, class F>
//void GeneticAlgorithm<G, F>::addRandomGenesToPopulation(int numberOfRandomGenes) {
//    for (int i = 0; i < numberOfRandomGenes; ++i) {
//        addToPopulation(_geneRandomiser.getValue());
//    }
//}


//template<class G, class F>
//void GeneticAlgorithm<G, F>::addToPopulation(G geneValue) {
//    auto fitness = _fitnessFunction.Fitness(geneValue);
//
//    Chromosome<G, F> chromosome(geneValue, fitness);
//
//    _population.add(chromosome);
//}


//
//template<typename G, typename F>
//void PopulationGenerator<G, F>::SelectFittest(IPopulation<G, F> &population,
//                                             int populationSize) {
//    _addedGenes = {};
//    _pq = {};
//
//    vector<Chromosome<G, F>> populationVector = population.getPopulationVector();
//
//    for (int i = 0; i < populationVector.size(); ++i) {
//        Chromosome<G, F> gene = populationVector[i];
//
//        const bool is_in = _addedGenes.find(gene.getValue()) != _addedGenes.end();
//
//        if (!is_in) {
//            _pq.push(gene);
//            _addedGenes.insert(gene.getValue());
//        }
//    }
//
//    vector<Chromosome<G, F>> nextPopulation;
//    while (nextPopulation.size() < populationSize && !_pq.empty()) {
//        Chromosome<G, F> topGene = _pq.top();
//        nextPopulation.push_back(topGene);
//        _pq.pop();
//    }
//
//    population.Replace(nextPopulation);
template<typename G, typename F>
IPopulation<G, F> *PopulationGenerator<G, F>::GenerateInitialPopulation(IPopulation<G, F> *population) {
    cout << "Generate initial population" << endl;

    return population;
}

template<typename G, typename F>
IPopulation<G, F> *
PopulationGenerator<G, F>::GenerateNextPopulation(IPopulation<G, F> *population, int populationSize) {
    cout << "Generate next population" << endl;
    //        _matingPool.InitialiseFromPopulation(_population);
//        _matingPool.Print();
//
//        _population.clear();
//
//        auto numberOfRandomGenes = ceil(_percentOfRandomPopulation.getValue() * _populationSize);
//        addRandomGenesToPopulation((int) numberOfRandomGenes);
//
//        while (_population.size() < _populationSize) {
//            // TODO: Parent selection
//            auto parent1 = _matingPool.GetEligibleParent();
//            auto parent2 = _matingPool.GetEligibleParent();
//
//            // Parent1 should not be the same as parent2
//            while (parent1 == parent2) {
//                parent2 = _matingPool.GetEligibleParent();
//            }
//
//            auto child = _breeder.Breed(parent1, parent2);
//            child = _mutator.Mutate(child);
//
//            addToPopulation(child);
    return population;
}



//}
