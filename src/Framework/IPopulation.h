#ifndef GENETICALGORITHM_IPOPULATION_H
#define GENETICALGORITHM_IPOPULATION_H

#include <vector>
#include "models/Chromosome.h"

using namespace std;

template<typename C, typename F>
class IPopulation {
public:
    virtual void add(C chromosomeValue) = 0;

    virtual void add(Chromosome<C, F> chromosome) = 0;

    virtual void add(vector<Chromosome<C, F>> chromosomes) = 0;

    virtual void clear() = 0;

    virtual unsigned long size() = 0;

    virtual Chromosome<C, F> Fittest() = 0;

    virtual vector<Chromosome<C, F>> getPopulationVector() = 0;

    virtual void Print() = 0;
};

#endif //GENETICALGORITHM_IPOPULATION_H
