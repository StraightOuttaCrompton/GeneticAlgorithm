#include "StringMutator.h"
#include <random>
#include <iostream>


string StringMutator::Mutate(string str) {
    // TODO: Use _mutationRate here

    unsigned long length = str.size();

    random_device rd;     // only used once to initialise (seed) engine
    mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<int> uni(0, (int) length - 2); // guaranteed unbiased

    auto random_integer = uni(rng);

    char i = str[random_integer];
    char j = str[random_integer + 1];

//    cout << "random_integer: " << random_integer << endl;
//    cout << "i: " << i << endl;
//    cout << "j: " << j << endl;
//    cout << "--------: " << endl;

    str[random_integer] = j;
    str[random_integer + 1] = i;

    return str;
}