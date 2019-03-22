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
//    IFitnessFunction<C, F> &fitnessFunction
//    _fitnessFunction(fitnessFunction)
//    IFitnessFunction<C, F> &_fitnessFunction;

    PopulationGenerator(Probability percentOfRandomPopulation,
                        IMatingPool<G, F> &matingPool, IRandomiser<G> &randomiser, IBreeder<G> &breeder,
                        IMutator<G> &mutator)
            : _percentOfRandomPopulation(percentOfRandomPopulation), _matingPool(matingPool),
              _randomiser(randomiser), _breeder(breeder), _mutator(mutator) {}

    shared_ptr<IPopulation<G, F>>
    GenerateInitialPopulation(shared_ptr<IPopulation<G, F>> population, int populationSize);

    IPopulation<G, F> *GenerateNextPopulation(IPopulation<G, F> *population, int populationSize);

private:
    Probability _percentOfRandomPopulation;
    IMatingPool<G, F> &_matingPool;
    IRandomiser<G> &_randomiser;
    IBreeder<G> &_breeder;
    IMutator<G> &_mutator;
//    priority_queue<Chromosome<C, F>, std::vector<Chromosome<C, F>>, Order<C, F>> _pq;
//    set<C> _addedGenes; // Do I want genens to be unique?
};

#endif //GENETICALGORITHM_POPULATIONSELECTOR_H
