#ifndef GENETICALGORITHM_IMUTATOR_H
#define GENETICALGORITHM_IMUTATOR_H

template<typename C>
class IMutator {
public:
    virtual C Mutate(C chromosome) = 0;
};

#endif //GENETICALGORITHM_IMUTATOR_H
