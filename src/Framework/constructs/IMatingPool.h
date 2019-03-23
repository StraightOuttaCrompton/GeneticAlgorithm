#ifndef GENETICALGORITHM_IMATINGPOOL_H
#define GENETICALGORITHM_IMATINGPOOL_H

#include <memory>
#include "IPopulation.h"

template<class C, class F>
class IMatingPool {
public:
    virtual void InitialiseFromPopulation(shared_ptr<IPopulation<C, F>> population) = 0;

    virtual Chromosome<C, F> GetEligibleParent() = 0;
};

#endif //GENETICALGORITHM_IMATINGPOOL_H
