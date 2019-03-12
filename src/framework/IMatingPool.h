#ifndef GENETICALGORITHM_IMATINGPOOL_H
#define GENETICALGORITHM_IMATINGPOOL_H

template<class G>
class IMatingPool {
public:
    virtual G getEligibleParent() = 0;
};

#endif //GENETICALGORITHM_IMATINGPOOL_H
