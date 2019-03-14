#ifndef GENETICALGORITHM_STRINGMUTATOR_H
#define GENETICALGORITHM_STRINGMUTATOR_H

using namespace std;

#include "../framework/IMutator.h"
#include <string>

class StringMutator : public IMutator<string> {
public:
    string Mutate(string chromosome, int mutationRate);
};

#endif //GENETICALGORITHM_STRINGMUTATOR_H
