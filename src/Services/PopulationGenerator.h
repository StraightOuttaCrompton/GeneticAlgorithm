#ifndef GENETICALGORITHM_POPULATIONSELECTOR_H
#define GENETICALGORITHM_POPULATIONSELECTOR_H

using namespace std;

#include "../Models/Probability.h"
#include <memory>
#include "../Framework/constructs/IPopulationGenerator.h"
#include "../Framework/customisable/IRandomiser.h"
#include "../Framework/customisable/IBreeder.h"
#include "../Framework/customisable/IMutator.h"

template<typename C, typename F>
class PopulationGenerator : public IPopulationGenerator<C, F> {
public:
    PopulationGenerator(Probability percentOfRandomPopulation, IMatingPool<C, F> &matingPool,
                        IRandomiser<C> &randomiser, IBreeder<C> &breeder, IMutator<C> &mutator)
            : _percentOfRandomPopulation(percentOfRandomPopulation), _matingPool(matingPool),
              _randomiser(randomiser), _breeder(breeder), _mutator(mutator) {}

    void GenerateInitialPopulation(shared_ptr<IPopulation<C, F>> population, int populationSize);

    void GenerateNextPopulation(shared_ptr<IPopulation<C, F>> population, int populationSize);

private:
    Probability _percentOfRandomPopulation;
    IMatingPool<C, F> &_matingPool;
    IRandomiser<C> &_randomiser;
    IBreeder<C> &_breeder;
    IMutator<C> &_mutator;
//    set<C> _addedGenes; // Do I want genens to be unique?
};

#endif //GENETICALGORITHM_POPULATIONSELECTOR_H
