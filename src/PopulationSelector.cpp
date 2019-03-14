#include <iostream>
#include "PopulationSelector.h"
#include "MatingPool.h"

template<typename G, typename F>
void PopulationSelector<G, F>::PopulateMatingPool(IPopulation<G> &population, IFitnessFunction<G, F> &fitnessFunction,
                                                  IMatingPool<G, F> &matingPool) {
    cout << "Populate mating pool" << endl;

    matingPool.clearPool();

    auto populationVector = population.getPopulation();

    auto it = populationVector.begin();

    for (it; it != populationVector.end(); ++it) {
        auto fitness = fitnessFunction.Fitness(*it);
        matingPool.add(*it, fitness);
    }
}