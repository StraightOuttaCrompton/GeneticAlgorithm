#include <random>

#include "SCRandomiser.h"
#include <algorithm>

string SCRandomiser::getValue() {
    string alphabet = _charPool;

    shuffle(alphabet.begin(), alphabet.end(), mt19937(random_device()()));

    return alphabet;
}