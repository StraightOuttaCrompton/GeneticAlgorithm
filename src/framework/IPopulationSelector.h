#ifndef GENETICALGORITHM_IPOPULATIONSELECTOR_H
#define GENETICALGORITHM_IPOPULATIONSELECTOR_H

#include "IMatingPool.h"
#include "IFitnessFunction.h"
#include "IPopulation.h"

template<typename G, typename F>
class IPopulationSelector {
public:
    virtual void PopulateMatingPool(IPopulation<G> &population,
                                    IFitnessFunction<G, F> &fitnessFunction, IMatingPool<G, F> &matingPool) = 0;
};

#endif //GENETICALGORITHM_IPOPULATIONSELECTOR_H
