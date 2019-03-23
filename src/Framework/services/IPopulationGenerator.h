#ifndef GENETICALGORITHM_IPOPULATIONSELECTOR_H
#define GENETICALGORITHM_IPOPULATIONSELECTOR_H

#include <memory>
#include "IMatingPool.h"
#include "../implementations/IFitnessFunction.h"
#include "IPopulation.h"

template<typename G, typename F>
class IPopulationGenerator {
public:
    virtual shared_ptr <IPopulation<G, F>>
    GenerateInitialPopulation(shared_ptr <IPopulation<G, F>> population, int populationSize) = 0;

    virtual shared_ptr <IPopulation<G, F>>
    GenerateNextPopulation(shared_ptr <IPopulation<G, F>> population, int popultationSize) = 0;
};

#endif //GENETICALGORITHM_IPOPULATIONSELECTOR_H
