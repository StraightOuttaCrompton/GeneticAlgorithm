#include "Population.h"

template<class G>
void Population<G>::add(G gene) {
    _population.push_back(gene);
}

template<class G>
void Population<G>::replace(vector<G> nextPopulaion) {
    _population = nextPopulaion;
}

template<class G>
vector<G> Population<G>::getPopulation() {
    return _population;
}