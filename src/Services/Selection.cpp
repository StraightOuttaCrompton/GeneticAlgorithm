#include "Selection.h"
#include <math.h>

template<typename C, typename F>
void Selection<C, F>::InitialiseFromPopulation(IPopulation<C, F> &population) {
    vector<Chromosome<C, F>> populationVector = population.getPopulationVector();

    _populationSize = 0;
    _parentSelector.ClearItems();
    _survivorSelector.ClearItems();

    for (int i = 0; i < populationVector.size(); ++i) {
        Chromosome<C, F> chromosome = populationVector[i];
        pair<C, F> item = {chromosome.getValue(), chromosome.getFitness()};

        _parentSelector.AddItem(item);
        _survivorSelector.AddItem(item);
        _populationSize++;
    }
}

template<typename C, typename F>
Chromosome<C, F> Selection<C, F>::SelectParent() {
    pair<C, F> item = _parentSelector.SelectItem();

    Chromosome<C, F> chromosome(item.first, item.second);

    return chromosome;
}

template<typename C, typename F>
vector<Chromosome<C, F>> Selection<C, F>::SelectSurvivors(Probability percentage) {
    int numberOfFittest = ceil(percentage.getValue() * _populationSize);

    vector<Chromosome<C, F>> fittest;

    for (int i = 0; i < numberOfFittest; ++i) {
        pair<C, F> item = _survivorSelector.SelectItem();

        Chromosome<C, F> chromosome(item.first, item.second);
        fittest.push_back(chromosome);
    }

    return fittest;
}
