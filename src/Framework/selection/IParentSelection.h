#ifndef GENETICALGORITHM_IPARENTSELECTION_H
#define GENETICALGORITHM_IPARENTSELECTION_H

#include "../models/Chromosome.h"

template<typename C, typename F>
class IParentSelection {
public:
    // TODO: initialise from population instead of adding individual chromosomes
    virtual void addChromosome(Chromosome<C, F> chromosome) = 0;

    virtual Chromosome<C, F> selectChromosome() = 0;

    virtual void clearItems() = 0;
};

#endif //GENETICALGORITHM_IPARENTSELECTION_H
