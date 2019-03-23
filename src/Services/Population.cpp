#include <iostream>
#include "Population.h"

template<typename C, typename F>
void Population<C, F>::add(C chromosomeValue) {
    auto fitness = _fitnessFunction.Fitness(chromosomeValue);

    Chromosome<C, F> chromosome(chromosomeValue, fitness);

    _population.push_back(chromosome);
}

template<typename C, typename F>
void Population<C, F>::clear() {
    _population.clear();
}

template<typename C, typename F>
unsigned long Population<C, F>::size() {
    _population.size();
}

//template<typename C, typename F>
//void Population<C, F>::Replace(vector<Chromosome<C, F>> nextPopulation) {
//    _population = nextPopulation;
//}
//
template<typename C, typename F>
vector<Chromosome<C, F>> Population<C, F>::getPopulationVector() {
    return _population;
}
