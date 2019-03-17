#ifndef GENETICALGORITHM_MATINGPOOL_H
#define GENETICALGORITHM_MATINGPOOL_H

#include "framework/IMatingPool.h"
#include "utils/RouletteWheelSelection.h"
#include "framework/IPopulation.h"

using namespace std;

#include <vector>
#include <queue>

template<class G, class F>
class MatingPool : public IMatingPool<G, F> {
public:
    virtual void InitialiseFromPopulation(IPopulation<G, F> &population);

    G GetEligibleParent();

    void Print();

private:
    RouletteWheelSelection<G> _rouletteWheelSelection;
};

#endif //GENETICALGORITHM_MATINGPOOL_H
