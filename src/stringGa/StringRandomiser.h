#ifndef GENETICALGORITHM_STRINGRANDOMISER_H
#define GENETICALGORITHM_STRINGRANDOMISER_H

using namespace std;

#include "../framework/IGeneValueRandomiser.h"
#include <string>

class StringRandomiser : public IGeneValueRandomiser<string> {
public:
    string getValue();
};

#endif //GENETICALGORITHM_STRINGRANDOMISER_H
