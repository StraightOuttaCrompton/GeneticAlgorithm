#ifndef GENETICALGORITHM_STRINGMUTATOR_H
#define GENETICALGORITHM_STRINGMUTATOR_H

using namespace std;

#include "../framework/IMutator.h"
#include "../Probability.h"
#include <string>

class StringMutator : public IMutator<string> {
public:
    explicit StringMutator(Probability mutationRate) : _mutationRate(mutationRate) {};

    string Mutate(string str) override;

private:
    Probability _mutationRate;
};

#endif //GENETICALGORITHM_STRINGMUTATOR_H
