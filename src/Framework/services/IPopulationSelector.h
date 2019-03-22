#ifndef GENETICALGORITHM_IPOPULATIONSELECTOR_H
#define GENETICALGORITHM_IPOPULATIONSELECTOR_H

#include "IMatingPool.h"
#include "../implementations/IFitnessFunction.h"
#include "IPopulation.h"

template<typename G, typename F>
class IPopulationSelector {
public:
    virtual void
    SelectFittest(IPopulation<G, F> &population, int popultationSize) = 0;
};

#endif //GENETICALGORITHM_IPOPULATIONSELECTOR_H
