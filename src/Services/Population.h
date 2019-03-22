#ifndef GENETICALGORITHM_POPULATION_H
#define GENETICALGORITHM_POPULATION_H

using namespace std;

#include <queue>
#include "../Framework/services/IPopulation.h"


template<typename G, typename F>
class Population : public IPopulation<G, F> {
public:
    void add(Gene<G, F> gene);

    void clear();

    unsigned long size();

    void Replace(vector<Gene<G, F>> nextPopulation);

    vector<Gene<G, F>> getPopulationVector();

private:
    vector<Gene<G, F>> _population;
};

#endif //GENETICALGORITHM_POPULATION_H
