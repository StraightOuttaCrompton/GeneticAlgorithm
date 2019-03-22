#ifndef GENETICALGORITHM_POPULATIONSELECTOR_H
#define GENETICALGORITHM_POPULATIONSELECTOR_H

using namespace std;

#include "../Models/Probability.h"
#include <memory>
#include "../Framework/services/IPopulationGenerator.h"
#include "../Framework/implementations/IRandomiser.h"
#include "../Framework/implementations/IBreeder.h"
#include "../Framework/implementations/IMutator.h"

template<typename G, typename F>
class PopulationGenerator : public IPopulationGenerator<G, F> {
public:
//    TODO: Should fitness function be injected here?
//    IFitnessFunction<G, F> &fitnessFunction
//    _fitnessFunction(fitnessFunction)
//    IFitnessFunction<G, F> &_fitnessFunction;

    PopulationGenerator(Probability percentOfRandomPopulation,
                        IMatingPool<G, F> &matingPool, IRandomiser<G> &geneRandomiser, IBreeder<G> &breeder,
                        IMutator<G> &mutator)
            : _percentOfRandomPopulation(percentOfRandomPopulation), _matingPool(matingPool),
              _geneRandomiser(geneRandomiser), _breeder(breeder), _mutator(mutator) {}

    IPopulation<G, F> *GenerateInitialPopulation(IPopulation<G, F> *population);

    IPopulation<G, F> *GenerateNextPopulation(IPopulation<G, F> *population, int populationSize);

private:
    Probability _percentOfRandomPopulation;
    IMatingPool<G, F> &_matingPool;
    IRandomiser<G> &_geneRandomiser;
    IBreeder<G> &_breeder;
    IMutator<G> &_mutator;
//    priority_queue<Chromosome<G, F>, std::vector<Chromosome<G, F>>, Order<G, F>> _pq;
//    set<G> _addedGenes; // Do I want genens to be unique?
};

#endif //GENETICALGORITHM_POPULATIONSELECTOR_H
