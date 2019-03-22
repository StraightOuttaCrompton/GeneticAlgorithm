#include "GeneticAlgorithm.h"
#include <iostream>
#include <cmath>


template<class G, class F>
void GeneticAlgorithm<G, F>::Start() {
    cout << "Genetic algorithm Start" << endl;
//    IPopulation<G, F> *initialPopulation = _populationGenerator.GenerateInitialPopulation(&_population);
    auto initialPopulation = _populationGenerator.GenerateInitialPopulation(_population, _populationSize);
    cout << "Genetic algorithm Start" << endl;
//        _population.Replace(initialPopulation);

//    for (int j = 0; j < _generations; ++j) {
//        cout << "Generation: " << j + 1 << endl;
//        IPopulation<G, F> *nextPopulation = _populationGenerator.GenerateNextPopulation(&_population, _populationSize);
////        _population.Replace(nextPopulation);
//    }

    // TODO: Return fitest item, or return entire list in order of fitness?
}



