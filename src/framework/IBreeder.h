#ifndef GENETICALGORITHM_IBREEDER_H
#define GENETICALGORITHM_IBREEDER_H

template<class T>
class IBreeder {
public:
    virtual T Breed(T parent1, T parent2) = 0;
};

#endif //GENETICALGORITHM_IBREEDER_H
