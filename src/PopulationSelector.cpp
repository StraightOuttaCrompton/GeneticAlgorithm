#include "PopulationSelector.h"
#include "MatingPool.h"

template<class G, class F>
IMatingPool<G, F>
PopulationSelector<G, F>::CreateMatingPool(IPopulation<G> population, IFitnessFunction<G, F> fitnessFunction) {
    auto populationVector = population.getPopulation();

    auto it = populationVector.begin();

    MatingPool<G, F> matingPool;

    for (it; it != populationVector.end(); ++it) {
        auto fitness = fitnessFunction.Fitness(*it);
        matingPool.add(*it, fitness);
    }

    return matingPool;
}