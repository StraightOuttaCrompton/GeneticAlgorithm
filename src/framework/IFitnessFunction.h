#ifndef GENETICALGORITHM_IFITNESSFUNCTION_H
#define GENETICALGORITHM_IFITNESSFUNCTION_H

template<typename G, typename F>
class IFitnessFunction {
public:
    virtual F Fitness(G gene) = 0;
};

#endif //GENETICALGORITHM_IFITNESSFUNCTION_H
