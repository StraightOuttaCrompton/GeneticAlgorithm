#ifndef GENETICALGORITHM_FITNESSFUNCTION_H
#define GENETICALGORITHM_FITNESSFUNCTION_H

using namespace std;

#include <string>
#include "../../Framework/implementations/IFitnessFunction.h"

class SCFitnessFunction : public IFitnessFunction<string, int> {
public:

    int Fitness(string chromosome) override;
};


#endif //GENETICALGORITHM_FITNESSFUNCTION_H
