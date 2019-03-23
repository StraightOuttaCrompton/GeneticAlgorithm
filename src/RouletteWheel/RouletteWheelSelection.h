#ifndef GENETICALGORITHM_ROULETTEWHEELSELECTION_H
#define GENETICALGORITHM_ROULETTEWHEELSELECTION_H

using namespace std;

#include <vector>
#include "../Framework/selection/IParentSelection.h"
#include "../Framework/models/Chromosome.h"

template<typename C, typename F>
class RouletteWheelSelection : public IParentSelection<C, F> {
public:
    RouletteWheelSelection();

    void addChromosome(Chromosome<C, F> chromosome);

    Chromosome<C, F> selectChromosome();

    void clearItems();

private:
    void initialise();

    void calcTotal();

    double _total;
    double _smallestNegativeFitness;
    vector<Chromosome<C, F>> _items;
};


#endif //GENETICALGORITHM_ROULETTEWHEELSELECTION_H
