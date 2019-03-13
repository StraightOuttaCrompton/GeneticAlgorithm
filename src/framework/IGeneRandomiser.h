#ifndef GENETICALGORITHM_IRANDOMISER_H
#define GENETICALGORITHM_IRANDOMISER_H

template<typename G>
class IGeneRandomiser {
    virtual G getRandomGene() = 0;
};

#endif //GENETICALGORITHM_IRANDOMISER_H
