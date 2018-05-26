#ifndef PATHS_IN_GRAPHS_ADDRANDOMEDGES_H
#define PATHS_IN_GRAPHS_ADDRANDOMEDGES_H

#include "../datastructures/graphs/AListGraph.h"

void AddRandomEdges(Graph &graph, int cantNodes, int minWeight, int maxWeight);
bool isComplete(Graph &graph);

#endif //PATHS_IN_GRAPHS_ADDRANDOMEDGES_H
