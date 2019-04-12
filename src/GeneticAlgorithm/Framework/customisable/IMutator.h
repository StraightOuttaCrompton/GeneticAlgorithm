#ifndef GENETICALGORITHM_IMUTATOR_H
#define GENETICALGORITHM_IMUTATOR_H

#include "../../../Models/Probability.h"

template<typename C>
class IMutator {
public:
    virtual void setMutationRate(Probability mutationRate) = 0;

    virtual C Mutate(C chromosome) = 0;
};

#endif //GENETICALGORITHM_IMUTATOR_H
