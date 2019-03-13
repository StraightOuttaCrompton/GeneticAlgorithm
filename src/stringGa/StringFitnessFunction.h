#ifndef GENETICALGORITHM_FITNESSFUNCTION_H
#define GENETICALGORITHM_FITNESSFUNCTION_H

using namespace std;

#include <string>
#include "../framework/IFitnessFunction.h"

class StringFitnessFunction : IFitnessFunction<string, int> {
public:
    int Fitness(string chromosome);
};


#endif //GENETICALGORITHM_FITNESSFUNCTION_H
