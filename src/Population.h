#ifndef GENETICALGORITHM_POPULATION_H
#define GENETICALGORITHM_POPULATION_H

#include "framework/IPopulation.h"

template<class G>
class Population : IPopulation<G> {
public:
    void add(G gene);

    void replace(vector<G> nextPopulaion);

    vector<G> getPopulation();

private:
    vector<G> _population;
};


#endif //GENETICALGORITHM_POPULATION_H
