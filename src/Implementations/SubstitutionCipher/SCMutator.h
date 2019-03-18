#ifndef GENETICALGORITHM_STRINGMUTATOR_H
#define GENETICALGORITHM_STRINGMUTATOR_H

using namespace std;

#include "../../Framework/implementations/IMutator.h"
#include "../../Models/Probability.h"
#include <string>

class SCMutator : public IMutator<string> {
public:
    explicit SCMutator(Probability mutationRate) : _mutationRate(mutationRate) {};

    string Mutate(string str) override;

private:
    Probability _mutationRate;
};

#endif //GENETICALGORITHM_STRINGMUTATOR_H
