cmake_minimum_required(VERSION 3.13)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(GeneticAlgorithm src/main.cpp src/framework/IFitnessFunction.h src/framework/IBreeder.h src/framework/IMutator.h src/framework/IGeneRandomiser.h src/stringGa/StringFitnessFunction.cpp src/stringGa/StringFitnessFunction.h src/stringGa/StringBreeder.cpp src/stringGa/StringBreeder.h src/stringGa/StringMutator.cpp src/stringGa/StringMutator.h src/Evolution.cpp src/Evolution.h src/framework/IPopulation.h src/framework/IMatingPool.h src/framework/IPopulationSelector.h src/stringGa/StringRandomiser.cpp src/stringGa/StringRandomiser.h src/MatingPool.cpp src/MatingPool.h src/Population.cpp src/Population.h src/PopulationSelector.cpp src/PopulationSelector.h src/utils/RouletteWheelSelection.cpp src/utils/RouletteWheelSelection.h src/utils/RouletteItem.h)