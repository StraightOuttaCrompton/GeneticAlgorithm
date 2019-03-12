#ifndef GENETICALGORITHM_POPULATIONSELECTOR_H
#define GENETICALGORITHM_POPULATIONSELECTOR_H


#include "framework/IPopulationSelector.h"

template<class G, class F>
class PopulationSelector : IPopulationSelector<G, F> {
    IMatingPool<G, F> getMatingPool(IPopulation<G> population, IFitnessFunction<G, F> fitnessFunction);
};


#endif //GENETICALGORITHM_POPULATIONSELECTOR_H
