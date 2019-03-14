#ifndef GENETICALGORITHM_INDIVIDUAL_H
#define GENETICALGORITHM_INDIVIDUAL_H

// TODO: create interface?
template<class G, class F>
class Individual {
public:
    Individual(G gene, F fitness) : _gene(gene), _fitness(fitness) {};

    G getGene() {
        return _gene;
    }

private:
    G _gene;
    F _fitness;
};

#endif //GENETICALGORITHM_INDIVIDUAL_H
