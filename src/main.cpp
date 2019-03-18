#include <iostream>

#include "Population.h"
#include "Population.cpp" // Avoid linking error
#include "MatingPool.h"
#include "MatingPool.cpp" // Avoid linking error
#include "PopulationSelector.h"
#include "PopulationSelector.cpp" // Avoid linking error

#include "stringGa/StringBreeder.h"
#include "stringGa/StringFitnessFunction.h"
#include "stringGa/StringRandomiser.h"
#include "stringGa/StringMutator.h"

#include "Evolution.h"
#include "Evolution.cpp" // Avoid linking error

#include "Probability.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    const int initialPopulationSize = 5;
    const int generations = 4;
    Probability mutationRate(0.05);

//    const int initialPopulationSize = 100;
//    const int generations = 40;
//    Probability mutationRate(0.05);

    // Data structures
    Population<string, int> population;
    PopulationSelector<string, int> populationSelector;
    MatingPool<string, int> matingPool;

    // Customisable components
    StringBreeder breeder; // TODO: pass alphabet in constructor
    StringFitnessFunction fitnessFunction; // TODO: pass target in constructor
    StringRandomiser randomiser; // TODO: pass alphabet in constructor
    StringMutator mutator(mutationRate);

    Evolution<string, int> ga(initialPopulationSize, generations, population, populationSelector,
                              matingPool, fitnessFunction, randomiser, breeder, mutator);

    ga.Start();



// TODO: test with negative numbers

//    RouletteWheelSelection<string> rouletteWheelSelection;
//
//    rouletteWheelSelection.addItem("1", 1);
//    rouletteWheelSelection.addItem("2", 10);
//    rouletteWheelSelection.addItem("3", 100);
//    rouletteWheelSelection.addItem("4", 1000);
//    rouletteWheelSelection.addItem("5", 10000);
//
//
//    int one = 0;
//    int two = 0;
//    int three = 0;
//    int four = 0;
//    int five = 0;
//
//    for (int i = 0; i < 1000; ++i) {
//        string item = rouletteWheelSelection.selectItem();
//
//        if (item == "1") {
//            one++;
//        }
//        if (item == "2") {
//            two++;
//        }
//        if (item == "3") {
//            three++;
//        }
//        if (item == "4") {
//            four++;
//        }
//        if (item == "5") {
//            five++;
//        }
//    }
//
//    cout << "one " << to_string(one) << endl;
//    cout << "two " << to_string(two) << endl;
//    cout << "three " << to_string(three) << endl;
//    cout << "four " << to_string(four) << endl;
//    cout << "five " << to_string(five) << endl;

    return 0;
}