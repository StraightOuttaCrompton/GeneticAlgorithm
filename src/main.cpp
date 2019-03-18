#include <iostream>

#include "Services/Population.h"
#include "Services/Population.cpp" // Avoid linking error
#include "Services/MatingPool.h"
#include "Services/MatingPool.cpp" // Avoid linking error
#include "Services/PopulationSelector.h"
#include "Services/PopulationSelector.cpp" // Avoid linking error

#include "Implementations/SubstitutionCipher/SCBreeder.h"
#include "Implementations/SubstitutionCipher/SCFitnessFunction.h"
#include "Implementations/SubstitutionCipher/SCRandomiser.h"
#include "Implementations/SubstitutionCipher/SCMutator.h"

#include "GeneticAlgorithm.h"
#include "GeneticAlgorithm.cpp" // Avoid linking error

#include "Models/Probability.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;


//    const int initialPopulationSize = 5;
//    const int generations = 4;
//    Probability mutationRate(0.05);
//
////    const int initialPopulationSize = 100;
////    const int generations = 40;
////    Probability mutationRate(0.05);
//
//    // Services
//    Population<string, int> population;
//    PopulationSelector<string, int> populationSelector;
//    MatingPool<string, int> matingPool;
//
//    // Substitution cipher
//    SCBreeder scBreeder; // TODO: pass alphabet in constructor
//    SCFitnessFunction scFitnessFunction; // TODO: pass target in constructor
//    SCRandomiser scRandomiser; // TODO: pass alphabet in constructor
//    SCMutator scMutator(mutationRate);
//
//    GeneticAlgorithm<string, int> geneticAlgorithm(initialPopulationSize, generations, population, populationSelector,
//                                                   matingPool, scFitnessFunction, scRandomiser, scBreeder, scMutator);
//
//    geneticAlgorithm.Start();



// TODO: test with negative numbers

    RouletteWheelSelection<string> rouletteWheelSelection;

    rouletteWheelSelection.addItem("0", 0);
    rouletteWheelSelection.addItem("1", -1);
    rouletteWheelSelection.addItem("2", -2);
    rouletteWheelSelection.addItem("3", -3);
    rouletteWheelSelection.addItem("4", -4);
    rouletteWheelSelection.addItem("5", -5);


    int zero = 0;
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;

    for (int i = 0; i < 10000; ++i) {
        string item = rouletteWheelSelection.selectItem();

        if (item == "0") {
            zero++;
        }
        if (item == "1") {
            one++;
        }
        if (item == "2") {
            two++;
        }
        if (item == "3") {
            three++;
        }
        if (item == "4") {
            four++;
        }
        if (item == "5") {
            five++;
        }
    }

    cout << "zero " << to_string(zero) << endl;
    cout << "one " << to_string(one) << endl;
    cout << "two " << to_string(two) << endl;
    cout << "three " << to_string(three) << endl;
    cout << "four " << to_string(four) << endl;
    cout << "five " << to_string(five) << endl;

    return 0;
}