#ifndef GENETICALGORITHM_MATINGPOOL_H
#define GENETICALGORITHM_MATINGPOOL_H

#include <memory>
#include "../Framework/services/IMatingPool.h"
#include "../Framework/services/IPopulation.h"
#include "../Framework/services/IParentSelection.h"

template<typename C, typename F>
class MatingPool : public IMatingPool<C, F> {
public:
    explicit MatingPool(IParentSelection<C, F> &parentSelection) : _parentSelection(parentSelection) {}

    void InitialiseFromPopulation(shared_ptr<IPopulation<C, F>> population);

    Chromosome<C, F> GetEligibleParent();

private:
    IParentSelection<C, F> &_parentSelection;
};

#endif //GENETICALGORITHM_MATINGPOOL_H
