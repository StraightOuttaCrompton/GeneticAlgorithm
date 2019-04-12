#include <string>
#include <iostream>
#include "GeneticAlgorithmFactory.h"

#include "../Constructs/Population.h"
#include "../Constructs/Population.cpp"

#include "../Constructs/PopulationSelector.h"
#include "../Constructs/PopulationSelector.cpp"
//
//#include "../Constructs/PopulationGenerator.h"
//#include "../Constructs/PopulationGenerator.cpp"

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
void GeneticAlgorithmFactory<C, F>::GetObject() {

    Population<C, F> *population = new Population<C, F>(_fitnessFunction);

//    auto a = getSelector(Fittest);
//    auto b = getSelector(RouletteWheel);
    FittestSelector<C, F> a;
    FittestSelector<C, F> b;

//    PopulationSelector<C, F> *populationSelector = new PopulationSelector(a, b);
//    PopulationGenerator<C, F> *populationGenerator(
//            _params.percentOfRandomPopulation,
//            _params.percentOfFittestPopulation,
//            populationSelector,
//            _randomiser,
//            _breeder,
//            _mutator
//    );
//#include "../Constructs/PopulationSelector.cpp"

//    GeneticAlgorithm<C, F> *blah(
//            _params.populationSize,
//            _params.generations,
//            population,
//            populationGenerator
//    );

    cout << "hello" << endl;
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