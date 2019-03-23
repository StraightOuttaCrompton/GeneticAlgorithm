#ifndef GENETICALGORITHM_IMATINGPOOL_H
#define GENETICALGORITHM_IMATINGPOOL_H

#include "IPopulation.h"

template<class G, class F>
class IMatingPool {
public:
    virtual void InitialiseFromPopulation(shared_ptr<IPopulation<G, F>> population) = 0;

    virtual G GetEligibleParent() = 0;

    virtual void Print() = 0;
};

#endif //GENETICALGORITHM_IMATINGPOOL_H
