#ifndef GENETICALGORITHM_PROBABILITY_H
#define GENETICALGORITHM_PROBABILITY_H

#include <stdexcept>

using namespace std;

class Probability {
public:
    explicit Probability(double value) {
        if (value < 0 || value > 1) {
            throw runtime_error("Invalid probability");
        }
        _value = value;
    };

    double getValue() const {
        return _value;
    };

private:
    double _value;
};

#endif //GENETICALGORITHM_PROBABILITY_H
