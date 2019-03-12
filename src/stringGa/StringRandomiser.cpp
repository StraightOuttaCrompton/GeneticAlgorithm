#include "StringRandomiser.h"
#include <algorithm>

string StringRandomiser::getRandomGene() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    random_shuffle(alphabet.begin(), alphabet.end());

    return alphabet;
}