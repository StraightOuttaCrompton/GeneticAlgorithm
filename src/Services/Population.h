#ifndef GENETICALGORITHM_POPULATION_H
#define GENETICALGORITHM_POPULATION_H

using namespace std;

#include <queue>
#include "../Framework/constructs/IPopulation.h"
#include "../Framework/customisable/IFitnessFunction.h"

template<typename C, typename F>
class Population : public IPopulation<C, F> {
public:
    explicit Population(IFitnessFunction<C, F> &fitnessFunction) : _fitnessFunction(fitnessFunction) {}

    void add(C chromosomeValue);

    void add(Chromosome<C, F> chromosome);

    void add(vector<Chromosome<C, F>> chromosomes);

    void clear();

    unsigned long size();

    Chromosome<C, F> Fittest();

    vector<Chromosome<C, F>> getPopulationVector();

    void Print();

private:
    IFitnessFunction<C, F> &_fitnessFunction;
    vector<Chromosome<C, F>> _population;
    Chromosome<C, F> _fittest;
};

#endif //GENETICALGORITHM_POPULATION_H
