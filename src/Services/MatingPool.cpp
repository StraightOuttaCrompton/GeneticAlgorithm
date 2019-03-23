#include "MatingPool.h"
#include <iostream>

template<class C, class F>
void MatingPool<C, F>::InitialiseFromPopulation(shared_ptr<IPopulation<C, F>> population) {
    _rouletteWheelSelection.clearItems();

    // TODO: use iterable instead of gettingPopulationVector?
    auto populationVector = population->getPopulationVector();

    for (int i = 0; i < populationVector.size(); ++i) {
        Chromosome<C, F> gene = populationVector[i];
        _rouletteWheelSelection.addItem(gene.getValue(), gene.getFitness());
    }
}

template<class C, class F>
C MatingPool<C, F>::GetEligibleParent() {
    return _rouletteWheelSelection.selectItem();
}

template<class C, class F>
void MatingPool<C, F>::Print() {
    cout << "Mating pool: " << endl;
    _rouletteWheelSelection.print();
    cout << endl;
}