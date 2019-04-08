#include <iostream>
#include "Population.h"

template<typename C, typename F>
void Population<C, F>::add(Chromosome<C, F> chromosome) {
    // Check if chromosome already exists in population and skip adding it if it does
    const bool is_in = _addedValues.find(chromosome.GetValue()) != _addedValues.end();
    if (is_in) return;

    if (_population.size() == 0 || chromosome.GetFitness() > _fittest.GetFitness()) {
        _fittest = chromosome;
    }

    _population.push_back(chromosome);
    _addedValues.insert(chromosome.GetValue());
};

template<typename C, typename F>
void Population<C, F>::add(vector<Chromosome<C, F>> chromosomes) {
    for (int i = 0; i < chromosomes.size(); ++i) {
        Chromosome<C, F> chromosome = chromosomes[i];
        add(chromosome);
    }
};

template<typename C, typename F>
void Population<C, F>::add(C chromosomeValue) {
    auto fitness = _fitnessFunction.Fitness(chromosomeValue);

    Chromosome<C, F> chromosome(chromosomeValue, fitness);

    add(chromosome);
}

template<typename C, typename F>
void Population<C, F>::clear() {
    _population.clear();
    _addedValues = {};
}

template<typename C, typename F>
unsigned long Population<C, F>::size() {
    _population.size();
}

template<typename C, typename F>
Chromosome<C, F> Population<C, F>::Fittest() {
    return _fittest;
}

template<typename C, typename F>
vector<Chromosome<C, F>> Population<C, F>::getPopulationVector() {
    return _population;
}

template<typename C, typename F>
void Population<C, F>::Print() {
    for (int i = 0; i < _population.size(); ++i) {
        Chromosome<C, F> item = _population[i];
        cout << "item " << i + 1 << ": " << item.GetValue() << "   fitness: " << item.GetFitness() << endl;
    }
    cout << endl;
}
