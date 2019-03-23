#include "GeneticAlgorithm.h"
#include <iostream>

template<class C, class F>
Chromosome<string, int> GeneticAlgorithm<C, F>::Start() {
    _populationGenerator.GenerateInitialPopulation(_population, _populationSize);

    for (int j = 0; j < _generations; ++j) {
        cout << "Generation: " << j + 1 << endl;
        _populationGenerator.GenerateNextPopulation(_population, _populationSize);

        // _population.print();
    }

    return _population->Fittest();
}



