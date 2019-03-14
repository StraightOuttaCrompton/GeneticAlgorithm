#ifndef GENETICALGORITHM_STRINGRANDOMISER_H
#define GENETICALGORITHM_STRINGRANDOMISER_H

using namespace std;

#include "../framework/IGeneRandomiser.h"
#include <string>

class StringRandomiser : public IGeneRandomiser<string> {
public:
    string getRandomGene();
};


#endif //GENETICALGORITHM_STRINGRANDOMISER_H
