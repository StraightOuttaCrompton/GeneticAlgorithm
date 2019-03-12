#ifndef GENETICALGORITHM_GENETICALGORITHM_H
#define GENETICALGORITHM_GENETICALGORITHM_H


#include "framework/IBreeder.h"
#include "framework/IFitnessFunction.h"
#include "framework/IGeneRandomiser.h"
#include "framework/IMutator.h"
#include "framework/IPopulation.h"
#include "framework/IPopulationSelector.h"

template<class G, class F>
class GeneticAlgorithm {
public:
    GeneticAlgorithm(
            int initialPopulationSize, int generations, IPopulation<G> population, IBreeder<G> breeder,
            IFitnessFunction<G, F> fitnessFunction, IGeneRandomiser<G> geneRandomiser, IMutator<G> mutator,
            IPopulationSelector<G, F> populationSelector
    ) :
            _initialPopulationSize(initialPopulationSize), _population(population), _generations(generations),
            _breeder(breeder), _fitnessFunction(fitnessFunction), _geneRandomiser(geneRandomiser), _mutator(mutator),
            _populationSelector(populationSelector) {}

    void Start();

private:
    int _initialPopulationSize;
    int _generations;
    IPopulation<G> _population;
    IBreeder<G> _breeder;
    IFitnessFunction<G, F> _fitnessFunction;
    IGeneRandomiser<G> _geneRandomiser;
    IMutator<G> _mutator;
    IPopulationSelector<G, F> _populationSelector;
};

#endif //GENETICALGORITHM_GENETICALGORITHM_H
