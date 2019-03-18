#ifndef GENETICALGORITHM_STRINGRANDOMISER_H
#define GENETICALGORITHM_STRINGRANDOMISER_H

using namespace std;

#include "../../Framework/implementations/IRandomiser.h"
#include <string>

class SCRandomiser : public IRandomiser<string> {
public:
    string getValue() override;
};

#endif //GENETICALGORITHM_STRINGRANDOMISER_H
