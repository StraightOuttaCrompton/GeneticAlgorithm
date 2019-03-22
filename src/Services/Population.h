#ifndef GENETICALGORITHM_POPULATION_H
#define GENETICALGORITHM_POPULATION_H

using namespace std;

#include <queue>
#include "../Framework/services/IPopulation.h"


template<typename G, typename F>
class Population : public IPopulation<G, F> {
public:
    void add(Chromosome<G, F> gene);

    void clear();

    unsigned long size();

    void Replace(vector<Chromosome<G, F>> nextPopulation);

    vector<Chromosome<G, F>> getPopulationVector();

private:
    vector<Chromosome<G, F>> _population;
};

#endif //GENETICALGORITHM_POPULATION_H
