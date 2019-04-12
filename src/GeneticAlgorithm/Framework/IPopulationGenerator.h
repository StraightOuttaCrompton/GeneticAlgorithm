#ifndef GENETICALGORITHM_IPOPULATIONGENERATOR_H
#define GENETICALGORITHM_IPOPULATIONGENERATOR_H

#include "IPopulation.h"

template<typename C, typename F>
class IPopulationGenerator {
public:
    virtual void GenerateInitialPopulation(IPopulation<C, F> *population, int populationSize) = 0;

    virtual void GenerateNextPopulation(IPopulation<C, F> *population, int popultationSize) = 0;
};

#endif //GENETICALGORITHM_IPOPULATIONGENERATOR_H
