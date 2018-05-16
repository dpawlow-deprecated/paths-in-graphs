#ifndef PATHS_IN_GRAPHS_GRAPH_H
#define PATHS_IN_GRAPHS_GRAPH_H

#include "../types/types.h"
#include "Path.h"

class Graph {
public:
    virtual void AddEdge();
    virtual Path MinimumPath(Node start, Node finish);
    virtual bool ExistsEdge(Node start, Node finish);
};


#endif //PATHS_IN_GRAPHS_GRAPH_H
