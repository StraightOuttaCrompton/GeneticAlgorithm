#ifndef GENETICALGORITHM_IMATINGPOOL_H
#define GENETICALGORITHM_IMATINGPOOL_H

template<class G, class F>
class IMatingPool {
public:
    virtual void add(G item, F fitness) = 0;

    virtual void clearPool() = 0;

    virtual G getEligibleParent() = 0;

    virtual void print() = 0;
};

#endif //GENETICALGORITHM_IMATINGPOOL_H
