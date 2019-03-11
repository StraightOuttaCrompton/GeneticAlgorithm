#ifndef GENETICALGORITHM_IFITNESSFUNCTION_H
#define GENETICALGORITHM_IFITNESSFUNCTION_H

template<class C, class F>
class IFitnessFunction {
public:
    virtual F Fitness(C solution) = 0;

};

#endif //GENETICALGORITHM_IFITNESSFUNCTION_H
