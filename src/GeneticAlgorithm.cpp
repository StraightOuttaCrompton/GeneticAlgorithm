#include "GeneticAlgorithm.h"
#include <iostream>
#include <cmath>


template<class G, class F>
void GeneticAlgorithm<G, F>::Start() {
    // TODO: implement parent and survivor selections generally, so that the implementations can change
    // https://medium.com/datadriveninvestor/genetic-algorithms-selection-5634cfc45d78

    IPopulation<G, F> *initialPopulation = _populationGenerator.GenerateInitialPopulation(&_population);
//        _population.Replace(initialPopulation);

    for (int j = 0; j < _generations; ++j) {
        cout << "Generation: " << j + 1 << endl;
        IPopulation<G, F> *nextPopulation = _populationGenerator.GenerateNextPopulation(&_population, _populationSize);
//        _population.Replace(nextPopulation);
    }

    // TODO: Return fitest item, or return entire list in order of fitness?
}



