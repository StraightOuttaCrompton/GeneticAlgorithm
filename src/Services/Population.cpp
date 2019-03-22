#include <iostream>
#include "Population.h"

template<typename G, typename F>
void Population<G, F>::add(Chromosome<G, F> gene) {
    _population.push_back(gene);
}

template<typename G, typename F>
void Population<G, F>::clear() {
    _population.clear();
}

template<typename G, typename F>
unsigned long Population<G, F>::size() {
    _population.size();
}

template<typename G, typename F>
void Population<G, F>::Replace(vector<Chromosome<G, F>> nextPopulation) {
    _population = nextPopulation;
}

template<typename G, typename F>
vector<Chromosome<G, F>> Population<G, F>::getPopulationVector() {
    return _population;
}
