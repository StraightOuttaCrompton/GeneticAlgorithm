#ifndef GENETICALGORITHM_POPULATIONSELECTOR_H
#define GENETICALGORITHM_POPULATIONSELECTOR_H

using namespace std;

#include "../Models/Probability.h"
#include "../Framework/constructs/IPopulationGenerator.h"
#include "../Framework/customisable/IRandomiser.h"
#include "../Framework/customisable/IBreeder.h"
#include "../Framework/customisable/IMutator.h"
#include "../Framework/selection/IParentSelection.h"
#include "../Framework/selection/ISurvivorSelection.h"

template<typename C, typename F>
class PopulationGenerator : public IPopulationGenerator<C, F> {
public:
    PopulationGenerator(Probability percentOfRandomPopulation, IParentSelection<C, F> &parentSelection,
                        ISurvivorSelection<C, F> &survivorSelection, IRandomiser<C> &randomiser, IBreeder<C> &breeder,
                        IMutator<C> &mutator)
            : _percentOfRandomPopulation(percentOfRandomPopulation), _parentSelection(parentSelection),
              _survivorSelection(survivorSelection), _randomiser(randomiser), _breeder(breeder), _mutator(mutator) {}

    void GenerateInitialPopulation(IPopulation<C, F> &population, int populationSize);

    void GenerateNextPopulation(IPopulation<C, F> &population, int populationSize);

private:
    Probability _percentOfRandomPopulation;
    IParentSelection<C, F> &_parentSelection;
    ISurvivorSelection<C, F> &_survivorSelection;
    IRandomiser<C> &_randomiser;
    IBreeder<C> &_breeder;
    IMutator<C> &_mutator;
//    set<C> _addedGenes; // Do I want genens to be unique?
};

#endif //GENETICALGORITHM_POPULATIONSELECTOR_H
