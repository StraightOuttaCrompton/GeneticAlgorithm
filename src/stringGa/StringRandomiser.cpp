#include <random>

#include "StringRandomiser.h"
#include <algorithm>

string StringRandomiser::getValue() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    shuffle(alphabet.begin(), alphabet.end(), mt19937(random_device()()));

    return alphabet;
}