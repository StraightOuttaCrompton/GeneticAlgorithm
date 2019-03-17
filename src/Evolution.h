#ifndef GENETICALGORITHM_GENETICALGORITHM_H
#define GENETICALGORITHM_GENETICALGORITHM_H

#include "framework/IBreeder.h"
#include "framework/IFitnessFunction.h"
#include "framework/IGeneValueRandomiser.h"
#include "framework/IMutator.h"
#include "framework/IPopulation.h"
#include "framework/IPopulationSelector.h"

template<class G, class F>
class Evolution {
public:
    Evolution(
            int initialPopulationSize, int generations, IPopulation<G, F> &population,
            IPopulationSelector<G, F> &populationSelector, IMatingPool<G, F> &matingPool,
            IFitnessFunction<G, F> &fitnessFunction, IGeneValueRandomiser<G> &geneRandomiser, IBreeder<G> &breeder,
            IMutator<G> &mutator
    ) :
            _initialPopulationSize(initialPopulationSize),
            _generations(generations),
            _population(population),
            _populationSelector(populationSelector),
            _matingPool(matingPool),
            _fitnessFunction(fitnessFunction),
            _geneRandomiser(geneRandomiser),
            _breeder(breeder),
            _mutator(mutator) {}

    void Start();

private:
    void addToPopulation(G geneValue);

    int _initialPopulationSize;
    int _generations;
    IPopulation<G, F> &_population;
    IPopulationSelector<G, F> &_populationSelector;
    IMatingPool<G, F> &_matingPool;
    IFitnessFunction<G, F> &_fitnessFunction;
    IGeneValueRandomiser<G> &_geneRandomiser;
    IBreeder<G> &_breeder;
    IMutator<G> &_mutator;
};

#endif //GENETICALGORITHM_GENETICALGORITHM_H
