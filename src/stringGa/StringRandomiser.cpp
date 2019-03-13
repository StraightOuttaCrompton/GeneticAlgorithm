#include <random>

#include "StringRandomiser.h"
#include <algorithm>

string StringRandomiser::getRandomGene() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    shuffle(alphabet.begin(), alphabet.end(), std::mt19937(std::random_device()()));

    return alphabet;
}