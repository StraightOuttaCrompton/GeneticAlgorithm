#include "StringMutator.h"
#include <random>


string StringMutator::Mutate(string chromosome, int mutationRate) {
    int length = static_cast<int>(chromosome.size());

    random_device rd;     // only used once to initialise (seed) engine
    mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<int> uni(0, length - 1); // guaranteed unbiased

    auto random_integer = uni(rng);

    char i = chromosome[random_integer];
    char j = chromosome[random_integer + 1];

    chromosome[random_integer] = j;
    chromosome[random_integer + 1] = i;

    return chromosome;
}