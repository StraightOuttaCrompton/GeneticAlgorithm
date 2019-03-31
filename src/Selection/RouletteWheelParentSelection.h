#ifndef GENETICALGORITHM_ROULETTEWHEELSELECTION_H
#define GENETICALGORITHM_ROULETTEWHEELSELECTION_H

using namespace std;

#include <vector>
#include "../Framework/selection/IParentSelection.h"
#include "../Framework/constructs/IPopulation.h"
#include "../Framework/models/Chromosome.h"


template<typename C, typename F>
class RouletteWheelParentSelection : public IParentSelection<C, F> {
public:
    RouletteWheelParentSelection();

    void InitialiseFromPopulation(IPopulation<C, F> &population);

    Chromosome<C, F> SelectParent();

    void ClearItems();

private:
    void addChromosome(Chromosome<C, F> chromosome);

    void initialise();

    void calcTotal();

    double _total;
    double _smallestNegativeFitness;
    vector<Chromosome<C, F>> _items;
};


#endif //GENETICALGORITHM_ROULETTEWHEELSELECTION_H
