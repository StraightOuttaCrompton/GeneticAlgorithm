#ifndef GENETICALGORITHM_FITTESTSURVIVORSELECTION_H
#define GENETICALGORITHM_FITTESTSURVIVORSELECTION_H

#include <queue>
#include <set>
#include "../Framework/selection/ISurvivorSelection.h"

template<typename C, typename F>
struct Order {
    bool operator()(Chromosome<C, F> &lhs, Chromosome<C, F> &rhs) const {
        return lhs.getFitness() < rhs.getFitness();
    }
};

template<typename C, typename F>

class FittestSurvivorSelection : public ISurvivorSelection<C, F> {
public:
    FittestSurvivorSelection();

    void InitialiseFromPopulation(IPopulation<C, F> &population);

    vector<Chromosome<C, F>> GetFittest(Probability percentage);

    void ClearItems();

private:
    void addChromosome(Chromosome<C, F> chromosome);

    priority_queue<Chromosome<C, F>, vector<Chromosome<C, F>>, Order<C, F>> _pq;
    set<C> _addedChromosomes;

};

#endif //GENETICALGORITHM_FITTESTSURVIVORSELECTION_H
