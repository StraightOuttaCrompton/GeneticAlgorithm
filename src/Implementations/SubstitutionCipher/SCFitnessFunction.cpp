#include "SCFitnessFunction.h"

int SCFitnessFunction::Fitness(string chromosome) {
    int score = 0;

    for (int i = 0; i < chromosome.size(); ++i) {
        if (chromosome[i] == _target[i]) {
            score++;
        }
    }
    return score * score;
}
