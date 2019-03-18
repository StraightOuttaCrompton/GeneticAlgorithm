#ifndef GENETICALGORITHM_UTILS_H
#define GENETICALGORITHM_UTILS_H

using namespace std;

#include <random>
#include <set>
#include "../Models/Probability.h"

class Utils {
public:
    static int getRandomInt(int min, int max) {
        random_device rd;     // only used once to initialise (seed) engine
        mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
        uniform_int_distribution<int> uni(min, max); // guaranteed unbiased

        return uni(rng);
    }

    static double getRandomDouble(double min, double max) {
        random_device rd;
        mt19937 mt(rd());
        uniform_real_distribution<double> dist(min, max);

        return dist(mt);
    }

    static Probability getRandomProbability() {
        double d = getRandomDouble(0, 1);
        Probability p(d);

        return p;
    }

    template<typename T>
    static T getRandomItemFromSet(set<T> s) {
        int random_integer = getRandomInt(0, (int) s.size() - 1);

        return *next(s.begin(), random_integer);
    }
};

#endif //GENETICALGORITHM_UTILS_H
