#ifndef GENETICALGORITHM_ISURVIVORSELECTION_H
#define GENETICALGORITHM_ISURVIVORSELECTION_H

#include "../constructs/IPopulation.h"
#include "../../Models/Probability.h"

template<typename C, typename F>
class ISurvivorSelection {
public:
    virtual void InitialiseFromPopulation(IPopulation<C, F> &population) = 0;

    virtual vector<Chromosome<C, F>> GetFittest(Probability percentage) = 0;

    virtual void ClearItems() = 0;
};

#endif //GENETICALGORITHM_ISURVIVORSELECTION_H
