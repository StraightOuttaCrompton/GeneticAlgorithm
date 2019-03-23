#ifndef GENETICALGORITHM_IBREEDER_H
#define GENETICALGORITHM_IBREEDER_H

template<typename C>
class IBreeder {
public:
    virtual C Breed(C chromosome1, C chromosome2) = 0;
};

#endif //GENETICALGORITHM_IBREEDER_H
