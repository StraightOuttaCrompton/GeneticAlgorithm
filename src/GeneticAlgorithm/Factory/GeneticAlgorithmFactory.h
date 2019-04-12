#ifndef GENETICALGORITHM_GENETICALGORITHMFACTORY_H
#define GENETICALGORITHM_GENETICALGORITHMFACTORY_H

#include "../GeneticAlgorithm.h"
#include "../Framework/customisable/IBreeder.h"
#include "IFactory.h"
#include "../Framework/customisable/IFitnessFunction.h"
#include "../Framework/customisable/IMutator.h"
#include "../Framework/customisable/IRandomiser.h"
#include "../Framework/ISelector.h"

#include "../Selectors/RouletteWheelSelector.h"
#include "../Selectors/RouletteWheelSelector.cpp"
#include "../Selectors/FittestSelector.h"
#include "../Selectors/FittestSelector.cpp"
#include "../Selectors/Selectors.h"

template<typename C, typename F>
struct GeneticAlgorithmParams {
    int populationSize = 0;
    int generations = 0;
    Probability percentOfRandomPopulation = Probability(0);
    Probability percentOfFittestPopulation = Probability(0);
    Probability mutationRate = Probability(0);
    Selectors parentSelectorType = RouletteWheel;
    Selectors survivorSelectorType = Fittest;
};

template<typename C, typename F>
//: public IFactory<GeneticAlgorithm<C, F>>
class GeneticAlgorithmFactory {
public:
    explicit GeneticAlgorithmFactory(IBreeder<C> *breeder, IFitnessFunction<C, F> *fitnessFunction,
                                     IMutator<C> *mutator, IRandomiser<C> *randomiser) : _breeder(breeder),
                                                                                         _fitnessFunction(
                                                                                                 fitnessFunction),
                                                                                         _mutator(mutator),
                                                                                         _randomiser(randomiser) {};

    void SetParameters(GeneticAlgorithmParams<C, F> params);

    void GetObject();

private:

//    GeneticAlgorithm<C, F> *GetObject() override;
    ISelector<pair<C, F>> *getSelector(Selectors selectorName);

    GeneticAlgorithmParams<C, F> _params;
    IBreeder<C> *_breeder;
    IFitnessFunction<C, F> *_fitnessFunction;
    IMutator<C> *_mutator;
    IRandomiser<C> *_randomiser;
};

#endif //GENETICALGORITHM_GENETICALGORITHMFACTORY_H
