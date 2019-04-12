#ifndef GENETICALGORITHM_IPOPULATIONSELECTOR_H
#define GENETICALGORITHM_IPOPULATIONSELECTOR_H

#include "IPopulation.h"
#include "../../Models/Probability.h"

template<typename C, typename F>
class IPopulationSelector {
public:
    virtual void InitialiseFromPopulation(IPopulation<C, F> *population) = 0;

    virtual Chromosome<C, F> SelectParent() = 0;

    virtual vector<Chromosome<C, F>> SelectSurvivors(Probability percentage) = 0;
};

#endif //GENETICALGORITHM_IPOPULATIONSELECTOR_H
