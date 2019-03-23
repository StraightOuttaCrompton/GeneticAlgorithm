#include "GeneticAlgorithm.h"
#include <iostream>

template<class G, class F>
void GeneticAlgorithm<G, F>::Start() {
    // TODO: make void? why am I returning the initialPopulation?
    _populationGenerator.GenerateInitialPopulation(_population, _populationSize);

    for (int j = 0; j < _generations; ++j) {
        cout << "Generation: " << j + 1 << endl;
        _populationGenerator.GenerateNextPopulation(_population, _populationSize);

        // _population.print();
    }

    // TODO: Return fitest item, or return entire list in order of fitness?
}



