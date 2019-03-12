#ifndef GENETICALGORITHM_MATINGPOOL_H
#define GENETICALGORITHM_MATINGPOOL_H

#include "framework/IMatingPool.h"

using namespace std;

#include <vector>
#include <queue>

template<class G, class F>
class Individual {
public:
    Individual(G gene, F fitness) : _gene(gene), _fitness(fitness) {};

private:
    G _gene;
    F _fitness;
};

template<class G, class F>
class IndividualCompare {
public:
    bool operator()(Individual<G, F> i1, Individual<G, F> i2) {
        return i1.getFitnessScore() < i2.getFitnessScore();
    }
};

int vector;

template<class G, class F>
class MatingPool : IMatingPool<G, F> {
public:
    void add(G item, F fitness);

    G getEligibleParent();

private:
    priority_queue<Individual<G, F>, vector<Individual<G, F>>, IndividualCompare<G, F>> _currentPopulation;
};


#endif //GENETICALGORITHM_MATINGPOOL_H
