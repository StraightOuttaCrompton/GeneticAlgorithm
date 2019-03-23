#ifndef GENETICALGORITHM_ROULETTEWHEELSELECTION_H
#define GENETICALGORITHM_ROULETTEWHEELSELECTION_H

using namespace std;

#include <vector>
#include "RouletteItem.h"

template<typename T>
class RouletteWheelSelection {
public:
    RouletteWheelSelection();

    void addItem(T item, double prob);

    void clearItems();

    T selectItem();

private:
    void initialise();

    void calcTotal();

    double _total;
    double _smallestNegativeProb;
    vector<RouletteItem<T>> _items;
};


#endif //GENETICALGORITHM_ROULETTEWHEELSELECTION_H
