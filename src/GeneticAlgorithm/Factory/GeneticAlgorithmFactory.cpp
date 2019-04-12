#include <string>
#include <iostream>
#include "GeneticAlgorithmFactory.h"

#include "../Constructs/Population.h"
#include "../Constructs/Population.cpp"

#include "../Constructs/PopulationSelector.h"
#include "../Constructs/PopulationSelector.cpp"
//
#include "../Constructs/PopulationGenerator.h"
#include "../Constructs/PopulationGenerator.cpp"

//template<typename C, typename F>
//GeneticAlgorithm<C, F> *GeneticAlgorithmFactory<C, F>::GetObject() {
//    return new GeneticAlgorithm(
//            _params.populationSize,
//            _params.generations,
//            new Population(_fitnessFunction),
//            new PopulationGenerator(
//                    _params.percentOfRandomPopulation,
//                    _params.percentOfFittestPopulation,
//                    new PopulationSelector(_params.parentSelector, _params.survivorSelector),
//                    _randomiser,
//                    _breeder,
//                    _mutator
//            )
//    );
//}

template<typename C, typename F>
GeneticAlgorithm<C, F> *GeneticAlgorithmFactory<C, F>::GetObject() {

    Population<C, F> *population = new Population<C, F>(_fitnessFunction);

//    auto a = getSelector(Fittest);
//    auto b = getSelector(RouletteWheel);
    FittestSelector<C, F> a;
    FittestSelector<C, F> b;

    PopulationSelector<string, int> populationSelector(new FittestSelector<string, int>,
                                                       new FittestSelector<string, int>);

    PopulationGenerator<C, F> *populationGenerator = new PopulationGenerator<C, F>(
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
};