#ifndef GENETICALGORITHM_POPULATIONSELECTOR_H
#define GENETICALGORITHM_POPULATIONSELECTOR_H

#include "framework/IPopulationSelector.h"

template<typename G, typename F>
class PopulationSelector : public IPopulationSelector<G, F> {
public:
    void PopulateMatingPool(IPopulation<G> &population, IFitnessFunction<G, F> &fitnessFunction,
                            IMatingPool<G, F> &matingPool);
};

#endif //GENETICALGORITHM_POPULATIONSELECTOR_H
