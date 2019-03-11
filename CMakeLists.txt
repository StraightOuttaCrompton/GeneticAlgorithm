cmake_minimum_required(VERSION 3.13)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(GeneticAlgorithm src/main.cpp src/framework/IFitnessFunction.h src/framework/IBreeder.h src/framework/IMutator.h src/framework/IPopulation.h src/framework/IRandomiser.h)