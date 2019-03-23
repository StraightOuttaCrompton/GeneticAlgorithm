#ifndef GENETICALGORITHM_GENETICALGORITHM_H
#define GENETICALGORITHM_GENETICALGORITHM_H

#include "Framework/services/IPopulation.h"
#include "Framework/services/IPopulationGenerator.h"

template<class C, class F>
class GeneticAlgorithm {
public:
    GeneticAlgorithm(
            int populationSize, int generations, shared_ptr<IPopulation<C, F>> population,
            IPopulationGenerator<C, F> &populationGenerator
    ) : _populationSize(populationSize),
        _generations(generations),
        _population(population),
        _populationGenerator(populationGenerator) {}

    Chromosome<string, int> Start();

private:
    int _populationSize;
    int _generations;
    shared_ptr<IPopulation<C, F>> _population;
    IPopulationGenerator<C, F> &_populationGenerator;

};

#endif //GENETICALGORITHM_GENETICALGORITHM_H
