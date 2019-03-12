#ifndef GENETICALGORITHM_STRINGMUTATOR_H
#define GENETICALGORITHM_STRINGMUTATOR_H

using namespace std;

#include "../framework/IMutator.h"
#include <string>

class StringMutator : IMutator<string> {
    string Mutate(string chromosome);
};

#endif //GENETICALGORITHM_STRINGMUTATOR_H
