#ifndef GENETICALGORITHM_IPOPULATION_H
#define GENETICALGORITHM_IPOPULATION_H

#include <deque>

using namespace std;

template<class G>
class IPopulation {
public:
    virtual void add(G gene) = 0;

    virtual void replace(deque<G> nextPopulation) = 0;
};

#endif //GENETICALGORITHM_IPOPULATION_H
