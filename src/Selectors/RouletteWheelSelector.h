#ifndef GENETICALGORITHM_ROULETTEWHEELSELECTION_H
#define GENETICALGORITHM_ROULETTEWHEELSELECTION_H

using namespace std;

#include "../Framework/ISelector.h"
#include <vector>

template<typename C, typename F>
class RouletteWheelSelector : public ISelector<pair<C, F>> {
public:
    RouletteWheelSelector();

    pair<C, F> SelectItem();

    void AddItem(pair<C, F> item);

    void ClearItems();

private:
    void initialise();

    void calcTotal();

    double _total;
    double _smallestNegativeProb;
    vector<pair<C, F>> _items;
};


#endif //GENETICALGORITHM_ROULETTEWHEELSELECTION_H
