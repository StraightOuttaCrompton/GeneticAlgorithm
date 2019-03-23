#ifndef GENETICALGORITHM_FITNESSFUNCTION_H
#define GENETICALGORITHM_FITNESSFUNCTION_H

using namespace std;

#include <utility>
#include <string>
#include "../../Framework/customisable/IFitnessFunction.h"

class SCFitnessFunction : public IFitnessFunction<string, int> {
public:
    explicit SCFitnessFunction(string target) : _target(move(target)) {};

    int Fitness(string chromosome) override;

private:
    string _target;
};


#endif //GENETICALGORITHM_FITNESSFUNCTION_H
