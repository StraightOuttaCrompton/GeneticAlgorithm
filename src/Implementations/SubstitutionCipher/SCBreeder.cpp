#include "SCBreeder.h"
#include "../../Utils/Utils.h"

using namespace std;

string SCBreeder::Breed(string parent1, string parent2) {
    const unsigned long p1_length = parent1.length();
    const unsigned long p2_length = parent2.length();

    if (p1_length != p2_length) {
        throw invalid_argument("Parent lengths should be the same");
    }

    initialiseSets();

    const char childPlaceholder = '-';
    initialiseChild(p1_length, childPlaceholder);

    // Add matching chars from parents to child
    // if parent strings are "abcd" and "bcad",
    // then child will become "---d"
    for (string::size_type i = 0; i < p1_length; ++i) {
        char parent1Char = parent1[i];
        char parent2Char = parent2[i];

        if (parent1Char == parent2Char) {
            addCharToChild(parent1Char, i);
        }
    }

    // Choose randomly between parent1 char or parent2 char
    // If the char has been unused then add to child
    // TODO: instead of looping through, choose a random index
    for (string::size_type j = 0; j < p1_length; ++j) {
        if (_child[j] == childPlaceholder) {
            char parent1Char = parent1[j];
            char parent2Char = parent2[j];

            const bool p1_isInUsedChars = _usedChars.find(parent1Char) != _usedChars.end();
            const bool p2_isInUsedChars = _usedChars.find(parent2Char) != _usedChars.end();

            if (!p1_isInUsedChars && !p2_isInUsedChars) {
                set<char> parents = {parent1Char, parent2Char};
                char chosenChar = Utils::getRandomItemFromSet<char>(parents);
                addCharToChild(chosenChar, j);
                continue;
            }

            if (!p1_isInUsedChars) {
                addCharToChild(parent1Char, j);
                continue;
            }

            if (!p2_isInUsedChars) {
                addCharToChild(parent2Char, j);
            }
        }
    }

    // Fill in remaining child chars with unused chars from alphabet pool
    for (string::size_type k = 0; k < p1_length; ++k) {
        if (_child[k] == childPlaceholder) {
            char ch = Utils::getRandomItemFromSet<char>(_alphabetPool);
            addCharToChild(ch, k);
        }
    }

    return _child;
}

void SCBreeder::addCharToChild(char ch, unsigned long index) {
    _child[index] = ch;
    _alphabetPool.erase(ch);
    _usedChars.insert(ch);
}

void SCBreeder::initialiseSets() {
    _usedChars = {};
    for (int i = 0; i < _charPool.length(); ++i) {
        _alphabetPool.insert(_charPool[i]);
    }
}

void SCBreeder::initialiseChild(unsigned long length, char placeholder) {
    _child = "";
    for (string::size_type j = 0; j < length; ++j) {
        _child += placeholder;
    }
}