#ifndef GENETICALGORITHM_ROULETTEITEM_H
#define GENETICALGORITHM_ROULETTEITEM_H

template<typename T>
class RouletteItem {
public:
    RouletteItem(T item, double frequency) : _item(item), _frequency(frequency) {}

    T getItem() {
        return _item;
    }

    double getFrequency() {
        return _frequency;
    }

private:
    T _item;
    double _frequency;
};

#endif //GENETICALGORITHM_ROULETTEITEM_H
