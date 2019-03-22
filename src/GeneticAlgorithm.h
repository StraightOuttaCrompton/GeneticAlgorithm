#ifndef GENETICALGORITHM_GENETICALGORITHM_H
#define GENETICALGORITHM_GENETICALGORITHM_H

#include "Framework/implementations/IBreeder.h"
#include "Framework/implementations/IFitnessFunction.h"
#include "Framework/implementations/IRandomiser.h"
#include "Framework/implementations/IMutator.h"
#include "Framework/services/IPopulation.h"
#include "Framework/services/IPopulationSelector.h"
#include "Models/Probability.h"

template<class G, class F>
class GeneticAlgorithm {
public:
    GeneticAlgorithm(
            int populationSize, int generations, Probability percentOfRandomPopulation, IPopulation<G, F> &population,
            IPopulationSelector<G, F> &populationSelector, IMatingPool<G, F> &matingPool,
            IFitnessFunction<G, F> &fitnessFunction, IRandomiser<G> &geneRandomiser, IBreeder<G> &breeder,
            IMutator<G> &mutator
    ) :
            _populationSize(populationSize),
            _generations(generations),
            _percentOfRandomPopulation(percentOfRandomPopulation),
            _population(population),
            _populationSelector(populationSelector),
            _matingPool(matingPool),
            _fitnessFunction(fitnessFunction),
            _geneRandomiser(geneRandomiser),
            _breeder(breeder),
            _mutator(mutator) {}

    void Start();

private:
    void initialisePopulation();
    void addToPopulation(G geneValue);
    void addRandomGenesToPopulation(int numberOfRandomGenes);

    int _populationSize;
    int _generations;
    Probability _percentOfRandomPopulation;
    IPopulation<G, F> &_population;
    IPopulationSelector<G, F> &_populationSelector;
    IMatingPool<G, F> &_matingPool;
    IFitnessFunction<G, F> &_fitnessFunction;
    IRandomiser<G> &_geneRandomiser;
    IBreeder<G> &_breeder;
    IMutator<G> &_mutator;
};

#endif //GENETICALGORITHM_GENETICALGORITHM_H
