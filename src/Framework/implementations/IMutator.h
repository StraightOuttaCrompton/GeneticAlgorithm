#ifndef GENETICALGORITHM_IMUTATOR_H
#define GENETICALGORITHM_IMUTATOR_H

template<typename G>
class IMutator {
public:
    virtual G Mutate(G gene) = 0;
};

#endif //GENETICALGORITHM_IMUTATOR_H
