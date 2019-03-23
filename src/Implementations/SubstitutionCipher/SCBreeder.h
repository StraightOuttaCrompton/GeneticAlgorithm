#ifndef GENETICALGORITHM_STRINGBREEDER_H
#define GENETICALGORITHM_STRINGBREEDER_H

using namespace std;

#include "../../Framework/customisable/IBreeder.h"
#include <string>
#include <utility>
#include <set>

class SCBreeder : public IBreeder<string> {
public:
    explicit SCBreeder(string charPool) : _charPool(move(charPool)) {};

    string Breed(string parent1, string parent2) override;

private:
    void initialiseSets();

    void initialiseChild(unsigned long length, char placeholder);

    void addCharToChild(char ch, unsigned long index);

    set<char> _alphabetPool;
    set<char> _usedChars;
    string _child;
    string _charPool;
};


#endif //GENETICALGORITHM_STRINGBREEDER_H
