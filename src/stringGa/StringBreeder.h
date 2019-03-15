#ifndef GENETICALGORITHM_STRINGBREEDER_H
#define GENETICALGORITHM_STRINGBREEDER_H

using namespace std;

#include "../framework/IBreeder.h"
#include <string>
#include <set>

class StringBreeder : public IBreeder<string> {
public:
    string Breed(string parent1, string parent2);

private:
    void initialiseSets();

    void initialiseChild(unsigned long length, char placeholder);

    void addCharToChild(char ch, unsigned long index);

    set<char> _alphabetPool;
    set<char> _usedChars;
    string _child;
};


#endif //GENETICALGORITHM_STRINGBREEDER_H
