#ifndef PATHS_IN_GRAPHS_GRAPH_H
#define PATHS_IN_GRAPHS_GRAPH_H

#include <bits/unique_ptr.h>
#include "../../types/types.h"
#include "Path.h"

using namespace std;

class Graph {
public:
    virtual void AddEdge(Edge const &edge) = 0;
    virtual bool EdgeExists(Node start, Node finish) = 0;
    virtual bool EdgeInRange(Node start, Node finish) = 0;
    virtual Weight GetEdgeWeight(Node start, Node finish) = 0;

    virtual bool IsDirected() const = 0;

    virtual unsigned long GetNumberOfNodes() const = 0;
    virtual vector<Edge>::iterator GetEdgesBeginIterator(Node node) = 0;
    virtual vector<Edge>::iterator GetEdgesEndIterator(Node node) = 0;

    virtual Path MinimumPath(Node start, Node finish) = 0;
    virtual unique_ptr<Graph> MinimumSpanningTree() = 0;
};


#endif //PATHS_IN_GRAPHS_GRAPH_H