#ifndef GENETICALGORITHM_MATINGPOOL_H
#define GENETICALGORITHM_MATINGPOOL_H

#include <memory>
#include "../Framework/services/IMatingPool.h"
#include "../Framework/services/IPopulation.h"
#include "../RouletteWheel/RouletteWheelSelection.h"
#include "../RouletteWheel/RouletteWheelSelection.cpp"

template<class C, class F>
class MatingPool : public IMatingPool<C, F> {
public:
    void InitialiseFromPopulation(shared_ptr<IPopulation<C, F>> population);

    C GetEligibleParent();

private:
    RouletteWheelSelection<C> _rouletteWheelSelection;
};

#endif //GENETICALGORITHM_MATINGPOOL_H
