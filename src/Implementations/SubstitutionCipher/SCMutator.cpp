#include "SCMutator.h"
#include "../../Utils/Utils.h"

string SCMutator::Mutate(string str) {
    auto n = str.length();

    for (int i = 0; i < n; ++i) {
        Probability randomProb = Utils::getRandomProbability();
        if (randomProb.getValue() > _mutationRate.getValue()) {
            continue;
        }

        int r = Utils::getRandomInt(1, (int) n - 1); // check this can return 1 and n - 1

        auto swapIndex = (i + r) % n;

        char char1 = str[i];
        char char2 = str[swapIndex];

        str[i] = char2;
        str[swapIndex] = char1;
    }

    return str;
}