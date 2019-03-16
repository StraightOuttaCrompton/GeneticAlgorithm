#include <random>
#include <iostream>
#include "MatingPool.h"

template<class G, class F>
void MatingPool<G, F>::add(G item, F fitness) {
    _rouletteWheelSelection.addItem(item, (double) fitness);
}

template<class G, class F>
void MatingPool<G, F>::clearPool() {
    _rouletteWheelSelection.clearItems();
}

template<class G, class F>
G MatingPool<G, F>::getEligibleParent() {
    return _rouletteWheelSelection.selectItem();
}

template<class G, class F>
void MatingPool<G, F>::print() {
    cout << "Mating pool: " << endl;
    _rouletteWheelSelection.print();
    cout << endl;
}