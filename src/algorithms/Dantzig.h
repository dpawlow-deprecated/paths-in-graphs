
#ifndef PATHS_IN_GRAPHS_DANTZIG_H
#define PATHS_IN_GRAPHS_DANTZIG_H
#include "../datastructures/graphs/AMatrixGraph.h"
#include <climits>

AMatrixGraph DantzigAlgorithm(AMatrixGraph &matrixG);
Weight getMin(AMatrixGraph &matrixGraph, int limit, Node rowValue, Node columnValue);

#endif //PATHS_IN_GRAPHS_DANTZIG_H
