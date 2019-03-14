#ifndef GENETICALGORITHM_MATINGPOOL_H
#define GENETICALGORITHM_MATINGPOOL_H

#include "framework/IMatingPool.h"
#include "Individual.h"

using namespace std;

#include <vector>
#include <queue>

template<class G, class F>
class MatingPool : public IMatingPool<G, F> {
public:
    void add(G item, F fitness);

    void clearPool();

    G getEligibleParent();

private:
    vector<Individual<G, F>> _pool;
};

#endif //GENETICALGORITHM_MATINGPOOL_H
