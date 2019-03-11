#ifndef GENETICALGORITHM_IPOPULATION_H
#define GENETICALGORITHM_IPOPULATION_H

template<class C, class F>
class IPopulation {
public:
    virtual F getAverageFitness() = 0;

    virtual F getBestFitness() = 0;

    virtual C getFittestChromosome() = 0;
};

#endif //GENETICALGORITHM_IPOPULATION_H
