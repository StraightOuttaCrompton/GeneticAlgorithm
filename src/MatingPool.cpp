#include "MatingPool.h"

template<class G, class F>
void MatingPool<G, F>::add(G item, F fitness) {
    Individual<G, F> individual(item, fitness);

    _currentPopulation.push(individual);
}