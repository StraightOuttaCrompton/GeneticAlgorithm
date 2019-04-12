#ifndef GENETICALGORITHM_ISELECTOR_H
#define GENETICALGORITHM_ISELECTOR_H

template<typename T>
class ISelector {
public:
    virtual T SelectItem() = 0;

    virtual void AddItem(T item) = 0;

    virtual void ClearItems() = 0;
};

#endif //GENETICALGORITHM_ISELECTOR_H
