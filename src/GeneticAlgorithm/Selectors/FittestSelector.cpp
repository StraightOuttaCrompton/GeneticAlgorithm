#include "FittestSelector.h"

template<typename C, typename F>
FittestSelector<C, F>::FittestSelector() {
    ClearItems();
}

template<typename C, typename F>
pair <C, F> FittestSelector<C, F>::SelectItem() {
    auto length = _pq.size();

    if (length == 0) {
        throw length_error("No items to select from");
    }

    pair <C, F> top = _pq.top();
    _pq.pop();

    return top;
}

template<typename C, typename F>
void FittestSelector<C, F>::AddItem(pair <C, F> item) {
    C itemValue = item.first;
    const bool is_in = _addedItems.find(itemValue) != _addedItems.end();

    if (!is_in) {
        _pq.push(item);
        _addedItems.insert(itemValue);
    }
}

template<typename C, typename F>
void FittestSelector<C, F>::ClearItems() {
    _pq = priority_queue < pair < C, F >, vector < pair < C, F >>, Order<C, F>>
    ();
    _addedItems = {};
}
