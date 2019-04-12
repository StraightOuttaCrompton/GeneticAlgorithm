#include "GeneticAlgorithmFactory.h"

#include "../Constructs/Population.h"
#include "../Constructs/Population.cpp"
#include "../Constructs/PopulationSelector.h"
#include "../Constructs/PopulationSelector.cpp"
#include "../Constructs/PopulationGenerator.h"
#include "../Constructs/PopulationGenerator.cpp"

#include "../Selectors/FittestSelector.h"
#include "../Selectors/FittestSelector.cpp"
#include "../Selectors/RouletteWheelSelector.cpp"

#include <string>

template<typename C, typename F>
GeneticAlgorithm<C, F> *GeneticAlgorithmFactory<C, F>::GetObject() {
    _mutator->setMutationRate(_params.mutationRate);

    auto population = new Population<C, F>(_fitnessFunction);

    auto parentSelector = getSelector(_params.parentSelectorType);
    auto survivorSelector = getSelector(_params.survivorSelectorType);

    PopulationSelector<string, int> populationSelector(parentSelector, survivorSelector);

    auto populationGenerator = new PopulationGenerator<C, F>(
            _params.percentOfRandomPopulation,
            _params.percentOfFittestPopulation,
            &populationSelector,
            _randomiser,
            _breeder,
            _mutator
    );

    return new GeneticAlgorithm<C, F>(
            _params.populationSize,
            _params.generations,
            population,
            populationGenerator
    );
}

template<typename C, typename F>
void
GeneticAlgorithmFactory<C, F>::SetParameters(GeneticAlgorithmParams<C, F> params) {
    _params = params;
}


template<typename C, typename F>
ISelector<pair<C, F>> *GeneticAlgorithmFactory<C, F>::getSelector(Selectors selectorName) {
    if (selectorName == Fittest)
        return new FittestSelector<C, F>();

    if (selectorName == RouletteWheel)
        return new RouletteWheelSelector<C, F>();

    throw invalid_argument("Selection method not implemented in factory");
};