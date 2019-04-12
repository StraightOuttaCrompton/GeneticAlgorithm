//#include "GeneticAlgorithm/Constructs/Population.h"
//#include "GeneticAlgorithm/Constructs/Population.cpp" // Avoid linking error
//#include "GeneticAlgorithm/Constructs/PopulationGenerator.h"
//#include "GeneticAlgorithm/Constructs/PopulationGenerator.cpp" // Avoid linking error
//#include "GeneticAlgorithm/Constructs/PopulationSelector.h"
//#include "GeneticAlgorithm/Constructs/PopulationSelector.cpp" // Avoid linking error

#include "GeneticAlgorithm/Implementations/SubstitutionCipher/SCBreeder.h"
#include "GeneticAlgorithm/Implementations/SubstitutionCipher/SCFitnessFunction.h"
#include "GeneticAlgorithm/Implementations/SubstitutionCipher/SCRandomiser.h"
#include "GeneticAlgorithm/Implementations/SubstitutionCipher/SCMutator.h"

#include "GeneticAlgorithm/GeneticAlgorithm.h"
#include "GeneticAlgorithm/GeneticAlgorithm.cpp" // Avoid linking error

#include "GeneticAlgorithm/Factory/GeneticAlgorithmFactory.h"
#include "GeneticAlgorithm/Factory/GeneticAlgorithmFactory.cpp"

//#include "GeneticAlgorithm/Selectors/RouletteWheelSelector.h"
//#include "GeneticAlgorithm/Selectors/RouletteWheelSelector.cpp" // Avoid linking error
//#include "GeneticAlgorithm/Selectors/FittestSelector.h"
//#include "GeneticAlgorithm/Selectors/FittestSelector.cpp" // Avoid linking error


using namespace std;

int main() {
    // Todo:
    // 1. Add unit tests?
    // 2. consider termination condition
    // 3. Use struct? http://www.cplusplus.com/doc/tutorial/structures/
    // 4, IPopulation,capitalise public functions

    // n. Go through TODOs


    // Genetic algorithm parameters
    const int populationSize = 260;
    const int generations = 50;
    Probability percentOfRandomPopulation(0.05);
    Probability percentOfFittestPopulation(0.1);
    Probability mutationRate(0.05);

    // Substitution cipher
    const string charPool = "abcdefghijklmnopqrstuvwxyz";
    SCBreeder *scBreeder = new SCBreeder(charPool);
    SCFitnessFunction *scFitnessFunction = new SCFitnessFunction(charPool);
    SCRandomiser *scRandomiser = new SCRandomiser(charPool);
    SCMutator *scMutator = new SCMutator(mutationRate);


    PopulationSelector<string, int> *populationSelector = new PopulationSelector(new FittestSelector<string, int>,
                                                                                 new FittestSelector<string, int>);



//    GeneticAlgorithmFactory<string, int> factory(scBreeder, scFitnessFunction, scMutator, scRandomiser);
//
//    GeneticAlgorithmParams<string, int> params = {
//            1,
//            1,
//            Probability(0.1),
//            Probability(0.2),
//            Probability(0.3),
//            RouletteWheel,
//            Fittest
//    };
//
//    factory.SetParameters(params);
//
//    factory.GetObject();










    cout << "Hello" << endl;
//    cout << fittest.GetValue() << endl;
//    cout << fittest.GetFitness() << endl;

    return 0;
}
