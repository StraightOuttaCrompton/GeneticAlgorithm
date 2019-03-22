#ifndef GENETICALGORITHM_GENETICALGORITHM_H
#define GENETICALGORITHM_GENETICALGORITHM_H

#include "Framework/services/IPopulation.h"
#include "Framework/services/IPopulationGenerator.h"

template<class G, class F>
class GeneticAlgorithm {
public:
    GeneticAlgorithm(
            int populationSize, int generations, shared_ptr<IPopulation<G, F>> population,
            IPopulationGenerator<G, F> &populationGenerator
    ) : _populationSize(populationSize),
        _generations(generations),
        _population(population),
        _populationGenerator(populationGenerator) {}

    void Start();

private:
    int _populationSize;
    int _generations;
    shared_ptr<IPopulation<G, F>> _population;
    IPopulationGenerator<G, F> &_populationGenerator;

};

#endif //GENETICALGORITHM_GENETICALGORITHM_H
