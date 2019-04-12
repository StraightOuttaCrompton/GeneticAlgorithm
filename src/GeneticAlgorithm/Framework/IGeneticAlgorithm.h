#ifndef GENETICALGORITHM_IGENETICALGORITHM_H
#define GENETICALGORITHM_IGENETICALGORITHM_H

#include "models/Chromosome.h"

template<typename C, typename F>
class IGeneticAlgorithm {
public:
    virtual void Start() = 0;

    virtual Chromosome<C, F> GetFittest() = 0;
};

#endif //GENETICALGORITHM_IGENETICALGORITHM_H
