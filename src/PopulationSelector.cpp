#include "PopulationSelector.h"

template<typename G, typename F>
void PopulationSelector<G, F>::NaturalSelection(IPopulation<G, F> &population, IFitnessFunction<G, F> &fitnessFunction,
                                                int populationSize) {
    _addedGenes = {};
    _pq = {};

    vector<Gene<G, F>> populationVector = population.getPopulationVector();

    for (int i = 0; i < populationVector.size(); ++i) {
        Gene<G, F> gene = populationVector[i];

        const bool is_in = _addedGenes.find(gene.getValue()) != _addedGenes.end();

        if (!is_in) {
            _pq.push(gene);
            _addedGenes.insert(gene.getValue());
        }
    }

    vector<Gene<G, F>> nextPopulation;
    while (nextPopulation.size() < populationSize && !_pq.empty()) {
        Gene<G, F> topGene = _pq.top();
        nextPopulation.push_back(topGene);
        _pq.pop();
    }

    population.Replace(nextPopulation);
}