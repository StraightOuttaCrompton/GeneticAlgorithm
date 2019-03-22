#ifndef GENETICALGORITHM_IPOPULATION_H
#define GENETICALGORITHM_IPOPULATION_H

#include <vector>
#include "../models/Gene.h"

using namespace std;

template<typename G, typename F>
class IPopulation {
public:
    virtual void add(Gene<G, F> gene) = 0;

    virtual void clear() = 0;

    virtual unsigned long size() = 0;

    virtual void Replace(vector<Gene<G, F>> nextPopulation) = 0;

    virtual vector<Gene<G, F>> getPopulationVector() = 0;
};

#endif //GENETICALGORITHM_IPOPULATION_H
