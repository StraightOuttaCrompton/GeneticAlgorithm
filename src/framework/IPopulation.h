#ifndef GENETICALGORITHM_IPOPULATION_H
#define GENETICALGORITHM_IPOPULATION_H

template<class G>
class IPopulation {
public:
    virtual G getEligibleParent() = 0;

    virtual void addToPopulation(G gene) = 0;
};

#endif //GENETICALGORITHM_IPOPULATION_H
