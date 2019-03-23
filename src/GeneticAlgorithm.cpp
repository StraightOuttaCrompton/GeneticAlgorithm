#include "GeneticAlgorithm.h"
#include <iostream>

template<class C, class F>
void GeneticAlgorithm<C, F>::Start() {
    _populationGenerator.GenerateInitialPopulation(_population, _populationSize);

    for (int j = 0; j < _generations; ++j) {
        cout << "Generation: " << j + 1 << endl;
        _populationGenerator.GenerateNextPopulation(_population, _populationSize);

        setGlobalFittest();

        _population->Print();
    }
}

template<class C, class F>
void GeneticAlgorithm<C, F>::setGlobalFittest() {
    Chromosome<C, F> currentPopulationFittest = _population->Fittest();

    if (currentPopulationFittest.getFitness() >= _globalFittest.getFitness()) {
        _globalFittest = currentPopulationFittest;
    }
}

template<class C, class F>
Chromosome<C, F> GeneticAlgorithm<C, F>::GetFittest() {
    return _globalFittest;
}