#ifndef GENETICALGORITHM_MATINGPOOL_H
#define GENETICALGORITHM_MATINGPOOL_H

using namespace std;

#include "../Framework/services/IMatingPool.h"
#include "../Framework/services/IPopulation.h"
#include "../RouletteWheel/RouletteWheelSelection.h"
#include "../RouletteWheel/RouletteWheelSelection.cpp"

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
