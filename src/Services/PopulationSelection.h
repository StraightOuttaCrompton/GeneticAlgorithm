#ifndef GENETICALGORITHM_POPULATIONSELECTION_H
#define GENETICALGORITHM_POPULATIONSELECTION_H


#include "../Framework/constructs/IPopulationSelector.h"
#include "../Framework/selection/ISelector.h"

template<typename C, typename F>
class PopulationSelection : public IPopulationSelector<C, F> {
public:
    PopulationSelection(ISelector<pair<C, F>> &parentSelector, ISelector<pair<C, F>> &survivorSelector)
            : _parentSelector(
            parentSelector), _survivorSelector(survivorSelector) {
        _populationSize = 0;
    }

    void InitialiseFromPopulation(IPopulation<C, F> &population);

    Chromosome<C, F> SelectParent();

    vector<Chromosome<C, F>> SelectSurvivors(Probability percentage);

private:
    int _populationSize;
    ISelector<pair<C, F>> &_parentSelector;
    ISelector<pair<C, F>> &_survivorSelector;

};


#endif //GENETICALGORITHM_POPULATIONSELECTION_H
