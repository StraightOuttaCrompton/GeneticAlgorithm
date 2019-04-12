#ifndef GENETICALGORITHM_GENETICALGORITHM_H
#define GENETICALGORITHM_GENETICALGORITHM_H

#include "Framework/IGeneticAlgorithm.h"
#include "Framework/IPopulation.h"
#include "Framework/IPopulationGenerator.h"

template<class C, class F>
class GeneticAlgorithm : public IGeneticAlgorithm<C, F> {
public:
    GeneticAlgorithm(
            int populationSize, int generations, IPopulation<C, F> *population,
            IPopulationGenerator<C, F> *populationGenerator
    ) : _populationSize(populationSize),
        _generations(generations),
        _population(population),
        _populationGenerator(populationGenerator),
        _globalFittest() {}

    void Start();

    Chromosome<C, F> GetFittest();

private:
    int _populationSize;
    int _generations;
    IPopulation<C, F> *_population;
    IPopulationGenerator<C, F> *_populationGenerator;

    void setGlobalFittest();

    Chromosome<C, F> _globalFittest;
};

#endif //GENETICALGORITHM_GENETICALGORITHM_H
