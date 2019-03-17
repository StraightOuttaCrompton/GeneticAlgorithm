#ifndef GENETICALGORITHM_IRANDOMISER_H
#define GENETICALGORITHM_IRANDOMISER_H

template<typename G>
class IGeneValueRandomiser {
public:
    virtual G getValue() = 0;
};

#endif //GENETICALGORITHM_IRANDOMISER_H
