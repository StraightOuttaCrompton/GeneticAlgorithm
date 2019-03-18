#include "StringMutator.h"
#include "../Utils/Utils.h"

string StringMutator::Mutate(string str) {
    // TODO: Use _mutationRate here

    unsigned long length = str.size();

    auto random_integer = Utils::getRandomInt(0, (int) length - 2);

    char i = str[random_integer];
    char j = str[random_integer + 1];

    str[random_integer] = j;
    str[random_integer + 1] = i;

    return str;
}