#include <random>
#include <stdexcept>
#include <iostream>
#include "RouletteWheelSelection.h"

template<typename T>
RouletteWheelSelection<T>::RouletteWheelSelection() {
    _total = 0;
}

template<typename T>
void RouletteWheelSelection<T>::addItem(T item, double prob) {
    if (prob <= 0) {
        return;
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
        r = r - item.getFrequency();
        i++;
    }

    RouletteItem selectedItem = _items[i - 1];
    return selectedItem.getItem();
}
