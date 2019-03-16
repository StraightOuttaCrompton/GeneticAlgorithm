#ifndef GENETICALGORITHM_MATINGPOOL_H
#define GENETICALGORITHM_MATINGPOOL_H

#include "framework/IMatingPool.h"
#include "utils/RouletteWheelSelection.h"

using namespace std;

#include <vector>
#include <queue>

template<class G, class F>
class MatingPool : public IMatingPool<G, F> {
public:
    void add(G item, F fitness);

    void clearPool();

    G getEligibleParent();

    void print();

private:
    RouletteWheelSelection <G> _rouletteWheelSelection;
};

#endif //GENETICALGORITHM_MATINGPOOL_H
