#ifndef GENETICALGORITHM_IRANDOMISER_H
#define GENETICALGORITHM_IRANDOMISER_H

template<typename G>
class IGeneRandomiser {
public:
    virtual G getRandomGene() = 0;
};

#endif //GENETICALGORITHM_IRANDOMISER_H
