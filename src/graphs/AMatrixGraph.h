//
// Created by dante on 16.05.18.
//

#ifndef PATHS_IN_GRAPHS_AMATRIXGRAPH_H
#define PATHS_IN_GRAPHS_AMATRIXGRAPH_H


#include "Graph.h"

class AMatrixGraph: public Graph {

private:
    struct MatrixEdge {
        bool is_connected;
        Weight weight;

        MatrixEdge(){
            is_connected = false;
            weight = 0;
        }

        explicit MatrixEdge(bool connected) {
            is_connected = connected;
            weight = 0;
        }

        explicit MatrixEdge(Weight w) {
            is_connected = true;
            weight = w;
        }
    };

    vector<vector<MatrixEdge>> adjacency_matrix;
    bool is_directed;
    bool is_weighted;

public:
    Path MinimumPath(Node start, Node finish) override;
    bool ExistsEdge(Node start, Node finish) override;
    Weight GetEdgeWeight(Node start, Node finish);
    bool IsDirected();
    bool IsWeighted();

};


#endif //PATHS_IN_GRAPHS_AMATRIXGRAPH_H
