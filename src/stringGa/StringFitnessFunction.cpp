#include "StringFitnessFunction.h"

int StringFitnessFunction::Fitness(string chromosome) {
    int score = 0;
    string target = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < chromosome.size(); ++i) {
        if (chromosome[i] == target[i]) {
            score++;
        }
    }
    return score;
}
