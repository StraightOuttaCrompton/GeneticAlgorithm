#include "IPopulation.h"

#ifndef GENETICALGORITHM_IPOPULATIONSELECTOR_H
#define GENETICALGORITHM_IPOPULATIONSELECTOR_H

#include "IMatingPool.h"
#include "IFitnessFunction.h"

template<class G, class F>
class IPopulationSelector {
    virtual IMatingPool<G, F> CreateMatingPool(IPopulation<G> population, IFitnessFunction<G, F> fitnessFunction) = 0;
};

#endif //GENETICALGORITHM_IPOPULATIONSELECTOR_H
