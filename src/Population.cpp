#include "Population.h"

template<class G>
void Population<G>::add(G gene) {
    _population.push_back(gene);
}

template<class G>
void Population<G>::replace(deque<G> nextPopulaion) {
    _population = nextPopulaion;
}