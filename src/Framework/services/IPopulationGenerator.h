#ifndef GENETICALGORITHM_IPOPULATIONSELECTOR_H
#define GENETICALGORITHM_IPOPULATIONSELECTOR_H

#include <memory>
#include "IMatingPool.h"
#include "../implementations/IFitnessFunction.h"
#include "IPopulation.h"

template<typename G, typename F>
class IPopulationGenerator {
public:
    virtual IPopulation<G, F> *GenerateInitialPopulation(IPopulation<G, F> *population) = 0;

    virtual IPopulation<G, F> *
    GenerateNextPopulation(IPopulation<G, F> *population, int popultationSize) = 0;
};

#endif //GENETICALGORITHM_IPOPULATIONSELECTOR_H
