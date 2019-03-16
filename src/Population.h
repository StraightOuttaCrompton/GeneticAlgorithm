#ifndef GENETICALGORITHM_POPULATION_H
#define GENETICALGORITHM_POPULATION_H

#include "framework/IPopulation.h"

template<typename G>
class Population : public IPopulation<G> {
public:
    void add(G gene);

    void replace(vector<G> nextPopulation);

    vector<G> getPopulation();

private:
    vector<G> _population;
};


#endif //GENETICALGORITHM_POPULATION_H
