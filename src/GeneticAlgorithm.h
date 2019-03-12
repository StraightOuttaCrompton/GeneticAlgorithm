#ifndef GENETICALGORITHM_GENETICALGORITHM_H
#define GENETICALGORITHM_GENETICALGORITHM_H


#include "framework/IBreeder.h"
#include "framework/IFitnessFunction.h"
#include "framework/IGeneRandomiser.h"
#include "framework/IMutator.h"

template<class G, class F>
class GeneticAlgorithm {
public:
    GeneticAlgorithm(
            int size, int generations, IBreeder<G> breeder, IFitnessFunction<G, F> fitnessFunction,
            IGeneRandomiser<G> geneRandomiser, IMutator<G> mutator
    ) :
            _size(size), _generations(generations), _breeder(breeder), _fitnessFunction(fitnessFunction),
            _geneRandomiser(geneRandomiser), _mutator(mutator) {}

    void Start();

private:
    int _size;
    int _generations;
    IBreeder<G> _breeder;
    IFitnessFunction<G, F> _fitnessFunction;
    IGeneRandomiser<G> _geneRandomiser;
    IMutator<G> _mutator;
};


#endif //GENETICALGORITHM_GENETICALGORITHM_H
