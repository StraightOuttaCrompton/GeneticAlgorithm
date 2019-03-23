#include "GeneticAlgorithm.h"
#include <iostream>

template<class G, class F>
void GeneticAlgorithm<G, F>::Start() {
    cout << "Genetic algorithm Start" << endl;
//    IPopulation<G, F> *initialPopulation = _populationGenerator.GenerateInitialPopulation(&_population);

    // TODO: make void? why am I returning the initialPopulation?
    auto initialPopulation = _populationGenerator.GenerateInitialPopulation(_population, _populationSize);

    cout << "blah" << endl;
//        _population.Replace(initialPopulation);

    for (int j = 0; j < _generations; ++j) {
        auto nextPopulation = _populationGenerator.GenerateNextPopulation(_population, _populationSize);
        cout << "Generation: " << j + 1 << endl;
//        _population.Replace(nextPopulation);
    }

    // TODO: Return fitest item, or return entire list in order of fitness?
}



