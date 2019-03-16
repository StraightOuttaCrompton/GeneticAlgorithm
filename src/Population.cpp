#include <iostream>
#include "Population.h"

template<typename G>
void Population<G>::add(G gene) {
    _population.push_back(gene);
}

template<typename G>
void Population<G>::replace(vector<G> nextPopulation) {
    _population = nextPopulation;
}

template<typename G>
vector<G> Population<G>::getPopulation() {
    return _population;
}
