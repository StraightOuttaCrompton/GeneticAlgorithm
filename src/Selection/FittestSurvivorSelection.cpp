#include "FittestSurvivorSelection.h"


template<typename C, typename F>
FittestSurvivorSelection<C, F>::FittestSurvivorSelection() {
    ClearItems();
}

template<typename C, typename F>
void FittestSurvivorSelection<C, F>::InitialiseFromPopulation(IPopulation<C, F> &population) {
    ClearItems();

    // TODO: use iterable instead of gettingPopulationVector?
    auto populationVector = population.getPopulationVector();

    for (int i = 0; i < populationVector.size(); ++i) {
        Chromosome<C, F> chromosome = populationVector[i];
        addChromosome(chromosome);
    }
}

template<typename C, typename F>
vector<Chromosome<C, F>> FittestSurvivorSelection<C, F>::GetFittest(Probability percentage) {
    auto length = _pq.size();
    vector<Chromosome<C, F>> fittest;

    if (length == 0) {
        return fittest;
    }

    auto numberOfFittest = ceil(percentage.getValue() * length);

    for (int i = 0; i < numberOfFittest; ++i) {
        Chromosome<C, F> top = _pq.top();
        _pq.pop();

        fittest.push_back(top);
    }

    return fittest;
}

template<typename C, typename F>
void FittestSurvivorSelection<C, F>::ClearItems() {
    _pq = priority_queue<Chromosome<C, F>, vector<Chromosome<C, F>>, Order<C, F>>();
    _addedChromosomes = {};
}

template<typename C, typename F>
void FittestSurvivorSelection<C, F>::addChromosome(Chromosome<C, F> chromosome) {
    const bool is_in = _addedChromosomes.find(chromosome.getValue()) != _addedChromosomes.end();

    if (!is_in) {
        _pq.push(chromosome);
        _addedChromosomes.insert(chromosome.getValue());
    }
}
