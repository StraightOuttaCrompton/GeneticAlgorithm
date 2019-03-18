#ifndef GENETICALGORITHM_ROULETTEITEM_H
#define GENETICALGORITHM_ROULETTEITEM_H

template<typename T>
class RouletteItem {
public:
    RouletteItem(T item, double value) : _item(item), _value(value) {}

    T getItem() {
        return _item;
    }

    double getValue() {
        return _value;
    }

private:
    T _item;
    double _value;
};

#endif //GENETICALGORITHM_ROULETTEITEM_H
