#ifndef GENETICALGORITHM_IMATINGPOOL_H
#define GENETICALGORITHM_IMATINGPOOL_H

#include "IPopulation.h"

template<class C, class F>
class IMatingPool {
public:
    virtual void InitialiseFromPopulation(shared_ptr<IPopulation<C, F>> population) = 0;

    virtual C GetEligibleParent() = 0;

    virtual void Print() = 0;
};

#endif //GENETICALGORITHM_IMATINGPOOL_H
