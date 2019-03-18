#include "MatingPool.h"
#include <iostream>

template<class G, class F>
void MatingPool<G, F>::InitialiseFromPopulation(IPopulation<G, F> &population) {
    _rouletteWheelSelection.clearItems();
    auto populationVector = population.getPopulationVector();
    for (int i = 0; i < populationVector.size(); ++i) {
        Gene<G, F> gene = populationVector[i];
        _rouletteWheelSelection.addItem(gene.getValue(), gene.getFitness());
    }
}

template<class G, class F>
G MatingPool<G, F>::GetEligibleParent() {
    return _rouletteWheelSelection.selectItem();
}

template<class G, class F>
void MatingPool<G, F>::Print() {
    cout << "Mating pool: " << endl;
    _rouletteWheelSelection.print();
    cout << endl;
}