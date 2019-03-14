#ifndef GENETICALGORITHM_STRINGBREEDER_H
#define GENETICALGORITHM_STRINGBREEDER_H

using namespace std;

#include <string>
#include "../framework/IBreeder.h"

class StringBreeder : public IBreeder<string> {
public:
    string Breed(string parent1, string parent2);
};


#endif //GENETICALGORITHM_STRINGBREEDER_H
