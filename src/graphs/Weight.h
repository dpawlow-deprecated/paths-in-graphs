//
// Created by dante on 16.05.18.
//

#ifndef PATHS_IN_GRAPHS_WEIGHT_H
#define PATHS_IN_GRAPHS_WEIGHT_H


class Weight {
public:
    Weight();
    explicit Weight(long weight);

    long GetWeight();
    bool IsWeighted();

private:
    bool has_weight;
    long weight;
};


#endif //PATHS_IN_GRAPHS_WEIGHT_H
