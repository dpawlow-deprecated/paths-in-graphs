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

        explicit MatrixEdge(Weight w) {
            is_connected = true;
            weight = w;
        }
    };

    vector<vector<MatrixEdge>> adjacency_matrix;
    bool is_directed;

public:
    void AddEdge(Edge const &edge) override;
    bool EdgeExists(Node start, Node finish) override;
    Weight GetEdgeWeight(Node start, Node finish) override;

    bool IsDirected() override;

    unsigned long GetNumberOfNodes();
    vector<Edge>::iterator GetFirstIteratorEdges();

    Path MinimumPath(Node start, Node finish) override;
    unique_ptr<Graph> MinimumSpanningTree() override;
};


#endif //PATHS_IN_GRAPHS_AMATRIXGRAPH_H
