#ifndef GENETICALGORITHM_IBREEDER_H
#define GENETICALGORITHM_IBREEDER_H

template<typename G>
class IBreeder {
public:
    virtual G Breed(G gene1, G gene2) = 0;
};

#endif //GENETICALGORITHM_IBREEDER_H
