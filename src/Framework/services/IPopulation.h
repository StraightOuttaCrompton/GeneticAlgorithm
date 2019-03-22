#ifndef GENETICALGORITHM_IPOPULATION_H
#define GENETICALGORITHM_IPOPULATION_H

#include <vector>
#include "../models/Chromosome.h"

using namespace std;

template<typename G, typename F>
class IPopulation {
public:
    virtual void add(Chromosome<G, F> gene) = 0;

    virtual void clear() = 0;

    virtual unsigned long size() = 0;

    virtual void Replace(vector<Chromosome<G, F>> nextPopulation) = 0;

    virtual vector<Chromosome<G, F>> getPopulationVector() = 0;
};

#endif //GENETICALGORITHM_IPOPULATION_H
