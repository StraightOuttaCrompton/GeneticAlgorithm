cmake_minimum_required(VERSION 3.13)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(GeneticAlgorithm src/main.cpp src/framework/IFitnessFunction.h src/framework/IBreeder.h src/framework/IMutator.h src/framework/IGeneRandomiser.h src/stringGa/StringFitnessFunction.cpp src/stringGa/StringFitnessFunction.h src/stringGa/StringBreeder.cpp src/stringGa/StringBreeder.h src/stringGa/StringMutator.cpp src/stringGa/StringMutator.h src/GeneticAlgorithm.cpp src/GeneticAlgorithm.h src/framework/IPopulation.h src/framework/IMatingPool.h src/framework/IPopulationSelector.h)