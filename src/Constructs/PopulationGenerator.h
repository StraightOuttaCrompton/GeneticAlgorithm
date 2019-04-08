#ifndef GENETICALGORITHM_POPULATIONGENERATOR_H
#define GENETICALGORITHM_POPULATIONGENERATOR_H

#include "../Framework/IPopulation.h"
#include "../Framework/IPopulationGenerator.h"
#include "../Framework/IPopulationSelector.h"
#include "../Framework/customisable/IRandomiser.h"
#include "../Framework/customisable/IBreeder.h"
#include "../Framework/customisable/IMutator.h"
#include "../Models/Probability.h"

template<typename C, typename F>
class PopulationGenerator : public IPopulationGenerator<C, F> {
public:
    PopulationGenerator(Probability percentOfRandomPopulation, Probability percentOfFittestPopulation,
                        IPopulationSelector<C, F> &populationSelector, IRandomiser<C> &randomiser, IBreeder<C> &breeder,
                        IMutator<C> &mutator)
            : _percentOfRandomPopulation(percentOfRandomPopulation),
              _percentOfFittestPopulation(percentOfFittestPopulation), _populationSelector(populationSelector),
              _randomiser(randomiser), _breeder(breeder), _mutator(mutator) {
        if (percentOfRandomPopulation.GetValue() + percentOfFittestPopulation.GetValue() > 1) {
            throw invalid_argument("Percentage totals must be less than 1");
        }
    }

    void GenerateInitialPopulation(IPopulation<C, F> &population, int populationSize);

    void GenerateNextPopulation(IPopulation<C, F> &population, int populationSize);

private:
    Probability _percentOfRandomPopulation;
    Probability _percentOfFittestPopulation;
    IPopulationSelector<C, F> &_populationSelector;
    IRandomiser<C> &_randomiser;
    IBreeder<C> &_breeder;
    IMutator<C> &_mutator;
};

#endif //GENETICALGORITHM_POPULATIONGENERATOR_H
