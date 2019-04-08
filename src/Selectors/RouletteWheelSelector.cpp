#include "RouletteWheelSelector.h"
#include "../Utils/Utils.h"

template<typename C, typename F>
RouletteWheelSelector<C, F>::RouletteWheelSelector() {
    initialise();
}

template<class C, class F>
pair<C, F> RouletteWheelSelector<C, F>::SelectItem() {
    if (_items.size() < 1) {
        throw logic_error("No items to select from");
    }

    calcTotal();

    double r = Utils::GetRandomDouble(0, _total);

    int i = 0;
    while (r > 0) {
        pair<C, F> item = _items[i];
        F itemProb = item.second;
        r = r - (itemProb - _smallestNegativeProb);
        i++;
    }

    pair<C, F> selectedItem = _items[i - 1];

    return selectedItem;
}

template<typename C, typename F>
void RouletteWheelSelector<C, F>::AddItem(pair<C, F> item) {
    F itemProb = item.second;

    if (itemProb < _smallestNegativeProb) {
        _smallestNegativeProb = itemProb * 2;
    }

    _items.push_back(item);
}

template<typename C, typename F>
void RouletteWheelSelector<C, F>::ClearItems() {
    _items.clear();
    initialise();
}

template<typename C, typename F>
void RouletteWheelSelector<C, F>::initialise() {
    _total = 0;
    _smallestNegativeProb = 0;
}


template<typename C, typename F>
void RouletteWheelSelector<C, F>::calcTotal() {
    _total = 0;
    for (int i = 0; i < _items.size(); ++i) {
        pair<C, F> item = _items[i];
        F itemProb = item.second;

        _total += itemProb + abs(_smallestNegativeProb);
    }
}