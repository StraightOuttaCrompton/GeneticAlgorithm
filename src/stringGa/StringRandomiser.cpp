#include <random>

#include "StringRandomiser.h"
#include <algorithm>

string StringRandomiser::getValue() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    shuffle(alphabet.begin(), alphabet.end(), std::mt19937(std::random_device()()));

    return alphabet;
}