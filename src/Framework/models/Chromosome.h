#ifndef GENETICALGORITHM_STRINGGENE_H
#define GENETICALGORITHM_STRINGGENE_H

template<typename G, typename F>
class Chromosome {
public:
    Chromosome() = default;

    Chromosome(G value, F fitness) : _value(value), _fitness(fitness) {}

    G getValue() {
        return _value;
    }

    F getFitness() {
        return _fitness;
    }

private:
    G _value;
    F _fitness;
};

#endif //GENETICALGORITHM_STRINGGENE_H
