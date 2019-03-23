#ifndef GENETICALGORITHM_STRINGRANDOMISER_H
#define GENETICALGORITHM_STRINGRANDOMISER_H

using namespace std;

#include "../../Framework/customisable/IRandomiser.h"
#include <string>
#include <utility>

class SCRandomiser : public IRandomiser<string> {
public:
    explicit SCRandomiser(string charPool) : _charPool(move(charPool)) {};

    string getValue() override;

private:
    string _charPool;
};

#endif //GENETICALGORITHM_STRINGRANDOMISER_H
