#ifndef GENETICALGORITHM_STRINGMUTATOR_H
#define GENETICALGORITHM_STRINGMUTATOR_H

using namespace std;

#include "../framework/IMutator.h"
#include <string>

class StringMutator : public IMutator<string> {
public:
    StringMutator(int mutationRate) : _mutationRate(mutationRate) {};

    string Mutate(string chromosome);

private:
    int _mutationRate;
};

#endif //GENETICALGORITHM_STRINGMUTATOR_H
