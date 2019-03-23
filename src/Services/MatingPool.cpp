#include "MatingPool.h"

template<class C, class F>
void MatingPool<C, F>::InitialiseFromPopulation(shared_ptr<IPopulation<C, F>> population) {
    _parentSelection.clearItems();

    // TODO: use iterable instead of gettingPopulationVector?
    auto populationVector = population->getPopulationVector();

    for (int i = 0; i < populationVector.size(); ++i) {
        Chromosome<C, F> chromosome = populationVector[i];
        _parentSelection.addChromosome(chromosome);
    }
}

template<class C, class F>
Chromosome<C, F> MatingPool<C, F>::GetEligibleParent() {
    return _parentSelection.selectChromosome();
}
