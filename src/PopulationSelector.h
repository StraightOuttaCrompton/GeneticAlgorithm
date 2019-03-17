#ifndef GENETICALGORITHM_POPULATIONSELECTOR_H
#define GENETICALGORITHM_POPULATIONSELECTOR_H

using namespace std;

#include <queue>
#include "framework/IPopulationSelector.h"

template<typename G, typename F>
struct Order {
    bool operator()(Gene<G, F> &lhs, Gene<G, F> &rhs) const {
        return lhs.getFitness() < rhs.getFitness();
    }
};

template<typename G, typename F>
class PopulationSelector : public IPopulationSelector<G, F> {
public:
    void NaturalSelection(IPopulation<G, F> &population, IFitnessFunction<G, F> &fitnessFunction,
                          int populationSize);

private:
    priority_queue<Gene<G, F>, std::vector<Gene<G, F>>, Order<G, F>> _pq;
};

#endif //GENETICALGORITHM_POPULATIONSELECTOR_H
