#ifndef GENETICALGORITHM_POPULATIONSELECTOR_H
#define GENETICALGORITHM_POPULATIONSELECTOR_H

using namespace std;

#include "../Framework/services/IPopulationSelector.h"
#include <queue>
#include <set>

template<typename G, typename F>
struct Order {
    bool operator()(Gene<G, F> &lhs, Gene<G, F> &rhs) const {
        return lhs.getFitness() < rhs.getFitness();
    }
};

template<typename G, typename F>
class PopulationSelector : public IPopulationSelector<G, F> {
public:
    void SelectFittest(IPopulation<G, F> &population, int populationSize);

private:
    priority_queue<Gene<G, F>, std::vector<Gene<G, F>>, Order<G, F>> _pq;
    set<G> _addedGenes;
};

#endif //GENETICALGORITHM_POPULATIONSELECTOR_H
