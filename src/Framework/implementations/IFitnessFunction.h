#ifndef GENETICALGORITHM_IFITNESSFUNCTION_H
#define GENETICALGORITHM_IFITNESSFUNCTION_H

template<typename C, typename F>
class IFitnessFunction {
public:
    virtual F Fitness(C chromosome) = 0;
};

#endif //GENETICALGORITHM_IFITNESSFUNCTION_H
