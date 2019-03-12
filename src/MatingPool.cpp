#include <random>
#include "MatingPool.h"

template<class G, class F>
void MatingPool<G, F>::add(G item, F fitness) {
    Individual<G, F> individual(item, fitness);

    _pool.push_back(individual);
}

template<class G, class F>
G MatingPool<G, F>::getEligibleParent() {
    int length = _pool.size();

    random_device rd;     // only used once to initialise (seed) engine
    mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<int> uni(0, length - 1); // guaranteed unbiased

    auto random_integer = uni(rng);

    Individual individual = _pool(random_integer);

    return individual.getGene();
}