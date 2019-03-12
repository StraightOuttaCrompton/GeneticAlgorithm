#ifndef GENETICALGORITHM_IMUTATOR_H
#define GENETICALGORITHM_IMUTATOR_H

template<class G>
class IMutator {
    virtual G Mutate(G gene, int mutationRate) = 0;
};

#endif //GENETICALGORITHM_IMUTATOR_H
