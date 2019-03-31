#ifndef GENETICALGORITHM_IPARENTSELECTION_H
#define GENETICALGORITHM_IPARENTSELECTION_H

#include "../models/Chromosome.h"
#include "../constructs/IPopulation.h"

template<typename C, typename F>
class IParentSelection {
public:
    virtual void InitialiseFromPopulation(IPopulation<C, F> &population) = 0;

    virtual Chromosome<C, F> SelectParent() = 0;

    virtual void ClearItems() = 0;
};

#endif //GENETICALGORITHM_IPARENTSELECTION_H
