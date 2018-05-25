#ifndef PATHS_IN_GRAPHS_FLOYD_H
#define PATHS_IN_GRAPHS_FLOYD_H

#include "../types/types.h"
#include "../datastructures/graphs/AMatrixGraph.h"

Weight minimum(Weight first, Weight second);
AdjacencyMatrix FloydAlgorithm(AMatrixGraph matrixGraph);

#endif //PATHS_IN_GRAPHS_FLOYD_H
