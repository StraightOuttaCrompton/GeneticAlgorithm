#ifndef GENETICALGORITHM_POPULATION_H
#define GENETICALGORITHM_POPULATION_H

using namespace std;

#include <queue>
#include "framework/IPopulation.h"

//template<typename G, typename F>
//struct Order {
//    bool operator()(Gene<G, F> &lhs, Gene<G, F> &rhs) const {
//        return lhs.getFitness() < rhs.getFitness();
//    }
//};

template<typename G, typename F>
class Population : public IPopulation<G, F> {
public:
    void add(Gene<G, F> gene);

    vector<Gene<G, F>> getPopulationVector();

private:
    vector<Gene<G, F>> _population;
//    priority_queue<Gene<G, F>, std::vector<Gene<G, F>>, Order < G, F>> _population;
};

#endif //GENETICALGORITHM_POPULATION_H
