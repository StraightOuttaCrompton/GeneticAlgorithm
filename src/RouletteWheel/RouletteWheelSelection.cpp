#include "RouletteWheelSelection.h"
#include "../Utils/Utils.h"

#include <iostream>

template<typename C, typename F>
RouletteWheelSelection<C, F>::RouletteWheelSelection() {
    initialise();
}

template<class C, class F>
void RouletteWheelSelection<C, F>::InitialiseFromPopulation(IPopulation<C, F> &population) {
    ClearItems();

    // TODO: use iterable instead of gettingPopulationVector?
    auto populationVector = population.getPopulationVector();

    for (int i = 0; i < populationVector.size(); ++i) {
        Chromosome<C, F> chromosome = populationVector[i];
        addChromosome(chromosome);
    }
}

template<class C, class F>
Chromosome<C, F> RouletteWheelSelection<C, F>::SelectParent() {
    if (_items.size() < 1) {
        throw logic_error("No items to select from");
    }

    calcTotal();

    double r = Utils::getRandomDouble(0, _total);

    int i = 0;
    while (r > 0) {
        Chromosome<C, F> item = _items[i];
        r = r - (item.getFitness() - _smallestNegativeFitness);
        i++;
    }

    Chromosome<C, F> selectedItem = _items[i - 1];

    return selectedItem;
}

template<typename C, typename F>
void RouletteWheelSelection<C, F>::ClearItems() {
    _items.clear();
    initialise();
}

template<typename C, typename F>
void RouletteWheelSelection<C, F>::initialise() {
    _total = 0;
    _smallestNegativeFitness = 0;
}

template<typename C, typename F>
void RouletteWheelSelection<C, F>::addChromosome(Chromosome<C, F> chromosome) {
    if (chromosome.getFitness() < _smallestNegativeFitness) {
        _smallestNegativeFitness = chromosome.getFitness() * 2;
    }

    _items.push_back(chromosome);
}

template<typename C, typename F>
void RouletteWheelSelection<C, F>::calcTotal() {
    _total = 0;
    for (int i = 0; i < _items.size(); ++i) {
        Chromosome<C, F> item = _items[i];
        _total += item.getFitness() + abs(_smallestNegativeFitness);
    }
}