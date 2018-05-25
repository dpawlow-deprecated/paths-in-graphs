#ifndef PATHS_IN_GRAPHS_FLOYD_H
#define PATHS_IN_GRAPHS_FLOYD_H

#include "../types/types.h"
#include "../datastructures/graphs/AMatrixGraph.h"

class Floyd {
private:
    static Weight minimum(Weight first, Weight second);
public:
    static void floydAlgorithm(AMatrixGraph* matrixGraph);

};

#endif //PATHS_IN_GRAPHS_FLOYD_H
