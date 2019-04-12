#ifndef GENETICALGORITHM_FITTESTSELECTOR_H
#define GENETICALGORITHM_FITTESTSELECTOR_H

using namespace std;

#include "../Framework/ISelector.h"
#include <queue>
#include <set>

template<typename C, typename F>
struct Order {
    bool operator()(pair<C, F> &lhs, pair<C, F> &rhs) const {
        return lhs.second < rhs.second;
    }
};

template<typename C, typename F>
class FittestSelector : public ISelector<pair<C, F>> {
public:

    FittestSelector();

    pair<C, F> SelectItem();

    void AddItem(pair<C, F>);

    void ClearItems();

private:
    priority_queue<pair<C, F>, vector<pair<C, F>>, Order<C, F>> _pq;
    set<C> _addedItems;
};

#endif //GENETICALGORITHM_FITTESTSELECTOR_H
