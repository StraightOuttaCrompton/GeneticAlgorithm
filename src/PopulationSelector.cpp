#include <iostream>
#include "PopulationSelector.h"
#include "MatingPool.h"

template<typename G, typename F>
void PopulationSelector<G, F>::NaturalSelection(IPopulation<G, F> &population, IFitnessFunction<G, F> &fitnessFunction,
                                                int populationSize) {
    cout << "Natural selection" << endl;
}