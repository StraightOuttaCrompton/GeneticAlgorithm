#ifndef GENETICALGORITHM_IFACTORY_H
#define GENETICALGORITHM_IFACTORY_H

template<typename T>
class IFactory {
public:
    virtual T *GetObject() = 0;
};

#endif //GENETICALGORITHM_IFACTORY_H
