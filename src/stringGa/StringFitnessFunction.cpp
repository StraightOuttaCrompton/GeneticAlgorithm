#include "StringFitnessFunction.h"

int StringFitnessFunction::Fitness(string chromosome) {
    int score = 0;
    for (int i = 0; i < chromosome.size(); ++i) {
        if (chromosome[i] == 'a') {
            score++;
        }
    }
    return score;
}
