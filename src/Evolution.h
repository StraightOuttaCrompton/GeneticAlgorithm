#ifndef GENETICALGORITHM_GENETICALGORITHM_H
#define GENETICALGORITHM_GENETICALGORITHM_H

#include "framework/IBreeder.h"
#include "framework/IFitnessFunction.h"
#include "framework/IGeneRandomiser.h"
#include "framework/IMutator.h"
#include "framework/IPopulation.h"
#include "framework/IPopulationSelector.h"

template<class G, class F>
class Evolution {
public:
    Evolution(
            int initialPopulationSize, int generations, IPopulation<G> &population,
            IPopulationSelector<G, F> &populationSelector, IMatingPool<G, F> &matingPool,
            IFitnessFunction<G, F> &fitnessFunction, IGeneRandomiser<G> &geneRandomiser, IBreeder<G> &breeder,
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
    int _initialPopulationSize;
    int _generations;
    IPopulation<G> &_population;
    IPopulationSelector<G, F> &_populationSelector;
    IMatingPool<G, F> &_matingPool;
    IFitnessFunction<G, F> &_fitnessFunction;
    IGeneRandomiser<G> &_geneRandomiser;
    IBreeder<G> &_breeder;
    IMutator<G> &_mutator;
};

#endif //GENETICALGORITHM_GENETICALGORITHM_H
