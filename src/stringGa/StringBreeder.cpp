#include "StringBreeder.h"
#include <set>
#include <iostream>
#include <random>

// This implementation was quickly done and needs a tidier solution

using namespace std;

char getCharFromSet(set<char> s) {
    random_device rd;     // only used once to initialise (seed) engine
    mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<int> uni(0, s.size() - 1); // guaranteed unbiased

    auto random_integer = uni(rng);

    char randomChar = *std::next(s.begin(), random_integer);

    return randomChar;
}

char chooseChar(char c1, char c2) {
    random_device rd;     // only used once to initialise (seed) engine
    mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<int> uni(0, 1); // guaranteed unbiased

    auto random_integer = uni(rng);

    if (random_integer == 0) {
        return c1;
    } else {
        return c2;
    }
}

string StringBreeder::Breed(string parent1, string parent2) {
    set<char> alphabetPool = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                              'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    set<char> usedChars;

    string child;
    for (string::size_type j = 0; j < parent1.size(); ++j) {
        child += '-';
    }

    for (string::size_type i = 0; i < parent1.size(); ++i) {
        char parent1Char = parent1[i];
        char parent2Char = parent2[i];

        if (parent1Char == parent2Char) {
            alphabetPool.erase(parent1Char);
            usedChars.insert(parent1Char);
            child[i] = parent1Char;
        }
    }

    for (string::size_type k = 0; k < child.size(); ++k) {
        if (child[k] == '-') {
            char parent1Char = parent1[k];
            char parent2Char = parent2[k];


            const bool p1_is_in = usedChars.find(parent1Char) != usedChars.end();
            const bool p2_is_in = usedChars.find(parent2Char) != usedChars.end();

            if (!p1_is_in && !p2_is_in) {
                char chosenChar = chooseChar(parent1Char, parent2Char);
                child[k] = chosenChar;
                alphabetPool.erase(chosenChar);
                usedChars.insert(chosenChar);
                continue;
            }

            if (!p1_is_in) {
                child[k] = parent1Char;
                alphabetPool.erase(parent1Char);
                usedChars.insert(parent1Char);
                continue;
            }

            if (!p2_is_in) {
                child[k] = parent2Char;
                alphabetPool.erase(parent2Char);
                usedChars.insert(parent2Char);
                continue;
            }
        }
    }


    for (string::size_type k = 0; k < child.size(); ++k) {
        if (child[k] == '-') {
            char ch = getCharFromSet(alphabetPool);
            child[k] = ch;
            alphabetPool.erase(ch);
            usedChars.insert(ch);
        }
    }

    return child;
}