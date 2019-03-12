#ifndef GENETICALGORITHM_IMATINGPOOL_H
#define GENETICALGORITHM_IMATINGPOOL_H

template<class G, class F>
class IMatingPool {
public:
    virtual void add(G item, F fitness);

    virtual G getEligibleParent() = 0;
};

#endif //GENETICALGORITHM_IMATINGPOOL_H
