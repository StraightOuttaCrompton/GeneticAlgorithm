#ifndef GENETICALGORITHM_IPOPULATION_H
#define GENETICALGORITHM_IPOPULATION_H

#include <vector>

using namespace std;

template<class G>
class IPopulation {
public:
    virtual void add(G gene) = 0;

    virtual void replace(vector<G> nextPopulation) = 0;

    virtual vector<G> getPopulation() = 0;
};

#endif //GENETICALGORITHM_IPOPULATION_H
