//
// Created by dante on 16.05.18.
//

#ifndef PATHS_IN_GRAPHS_AMATRIXGRAPH_H
#define PATHS_IN_GRAPHS_AMATRIXGRAPH_H


#include "Graph.h"

class AMatrixGraph: public Graph {

public:
    Path MinimumPath(Node start, Node finish) override;
    bool ExistsEdge(Node start, Node finish) override;

private:
    vector<vector<Weight>> adjacency_matrix;

};


#endif //PATHS_IN_GRAPHS_AMATRIXGRAPH_H
