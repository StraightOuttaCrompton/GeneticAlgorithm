#ifndef GENETICALGORITHM_IRANDOMISER_H
#define GENETICALGORITHM_IRANDOMISER_H

template<typename C>
class IRandomiser {
public:
    virtual C getValue() = 0;
};

#endif //GENETICALGORITHM_IRANDOMISER_H
