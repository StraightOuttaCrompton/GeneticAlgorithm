#ifndef GENETICALGORITHM_POPULATIONSELECTOR_H
#define GENETICALGORITHM_POPULATIONSELECTOR_H

#include "framework/IPopulationSelector.h"

template<typename G, typename F>
class PopulationSelector : public IPopulationSelector<G, F> {
public:
    void NaturalSelection(IPopulation<G, F> &population, IFitnessFunction<G, F> &fitnessFunction,
                          int populationSize);
};

#endif //GENETICALGORITHM_POPULATIONSELECTOR_H
