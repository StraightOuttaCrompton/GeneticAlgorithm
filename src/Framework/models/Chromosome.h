#ifndef GENETICALGORITHM_STRINGGENE_H
#define GENETICALGORITHM_STRINGGENE_H

template<typename C, typename F>
class Chromosome {
public:
    Chromosome() = default;

    Chromosome(C value, F fitness) : _value(value), _fitness(fitness) {}

    C GetValue() {
        return _value;
    }

    F GetFitness() {
        return _fitness;
    }

private:
    C _value;
    F _fitness;
};

#endif //GENETICALGORITHM_STRINGGENE_H
