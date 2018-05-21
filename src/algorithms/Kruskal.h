#ifndef PATHS_IN_GRAPHS_KRUSKAL_H
#define PATHS_IN_GRAPHS_KRUSKAL_H


#include "../datastructures/graphs/AListGraph.h"

vector<Edge>* GetEdges(Graph &graph);
AListGraph* KruskalPathCompression(Graph &graph);
AListGraph* KruskalWithLists(Graph &graph);


#endif //PATHS_IN_GRAPHS_KRUSKAL_H
