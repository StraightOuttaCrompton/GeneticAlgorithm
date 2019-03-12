#include "StringFitnessFunction.h"

int StringFitnessFunction::Fitness(string chromosome) {
    return chromosome.size();
}
