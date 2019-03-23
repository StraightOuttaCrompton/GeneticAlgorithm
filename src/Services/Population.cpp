#include <iostream>
#include "Population.h"

template<typename C, typename F>
void Population<C, F>::add(C chromosomeValue) {
    auto fitness = _fitnessFunction.Fitness(chromosomeValue);

    Chromosome<C, F> chromosome(chromosomeValue, fitness);

    if (_population.size() == 0 || fitness > _fittest.getFitness()) {
        _fittest = chromosome;
    }

    _population.push_back(chromosome);
}

template<typename C, typename F>
void Population<C, F>::clear() {
    _population.clear();

//    Chromosome<C, F> chromosome;
//    _fittest = chromosome;
}

template<typename C, typename F>
unsigned long Population<C, F>::size() {
    _population.size();
}

template<typename C, typename F>
Chromosome<C, F> Population<C, F>::Fittest() {
    return _fittest;
}

template<typename C, typename F>
vector<Chromosome<C, F>> Population<C, F>::getPopulationVector() {
    return _population;
}
