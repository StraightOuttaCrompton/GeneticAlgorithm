#include <random>
#include <stdexcept>
#include <iostream>
#include "RouletteWheelSelection.h"

template<typename T>
RouletteWheelSelection<T>::RouletteWheelSelection() {
    initialise();
}

template<typename T>
void RouletteWheelSelection<T>::initialise() {
    _total = 0;
    _smallestProb = 0;
}

template<typename T>
void RouletteWheelSelection<T>::addItem(T item, double prob) {
    if (prob < _smallestProb) {
        _smallestProb = prob;
    }

    RouletteItem<T> rouletteItem(item, prob);

    _total += prob;
    _items.push_back(rouletteItem);
}

template<typename T>
T RouletteWheelSelection<T>::selectItem() {
    if (_items.size() < 1) {
        throw logic_error("No items to select from");
    }

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0, _total);

    double r = dist(mt);

    int i = 0;
    while (r > 0) {
        RouletteItem item = _items[i];
        r = r - (item.getFrequency() - _smallestProb);
        i++;
    }

    RouletteItem selectedItem = _items[i - 1];
    return selectedItem.getItem();
}

template<typename T>
void RouletteWheelSelection<T>::clearItems() {
    _items.clear();
    initialise();
}

template<typename T>
void RouletteWheelSelection<T>::print() {
    cout << "smallest prob: " << _smallestProb << endl;
    for (int i = 0; i < _items.size(); ++i) {
        RouletteItem item = _items[i];
        cout << "item: " << item.getItem() << "   fitness: " << item.getFrequency() << endl;
    }
}