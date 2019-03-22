#ifndef GENETICALGORITHM_POPULATION_H
#define GENETICALGORITHM_POPULATION_H

using namespace std;

#include <queue>
#include "../Framework/services/IPopulation.h"
#include "../Framework/implementations/IFitnessFunction.h"


template<typename C, typename F>
class Population : public IPopulation<C, F> {
public:
    explicit Population(IFitnessFunction<C, F> &fitnessFunction) : _fitnessFunction(fitnessFunction) {}

    void add(C chromosomeValue);

    void clear();

//    unsigned long size();

//    void Replace(vector<Chromosome<C, F>> nextPopulation);

    vector<Chromosome<C, F>> getPopulationVector();

private:
    IFitnessFunction<C, F> &_fitnessFunction;
    vector<Chromosome<C, F>> _population;
};

#endif //GENETICALGORITHM_POPULATION_H
