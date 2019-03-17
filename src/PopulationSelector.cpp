#include <iostream>
#include "PopulationSelector.h"
#include "MatingPool.h"

template<typename G, typename F>
void PopulationSelector<G, F>::NaturalSelection(IPopulation<G, F> &population, IFitnessFunction<G, F> &fitnessFunction,
                                                int populationSize) {
    cout << "Natural selection" << endl;

    vector<Gene<G, F>> populationVector = population.getPopulationVector();
    for (int i = 0; i < populationVector.size(); ++i) {
        Gene<G, F> gene = populationVector[i];

        _pq.push(gene);
    }

    vector<Gene<G, F>> nextPopulation;
    for (int j = 0; j < populationSize; ++j) {
        nextPopulation.push_back(_pq.top());
        _pq.pop();
    }

    population.Replace(nextPopulation);
}